#include<bits/stdc++.h>
using namespace std;
struct trienode{
	int countn;
	trienode * child[4];
	trienode()
	{
		countn=0;
		for(int i=0;i<4;i++) child[i]=NULL;
	}
}* root;
int insert(const string &str)
{
	trienode* curr = root;
	int len= (int)str.size(),maxx=0,xx=1;
	for(int i=0;i<len;i++)
	{
		int temp;
		if(str[i]=='A') temp=0;
		else if(str[i]=='C') temp=1;
		else if(str[i]=='G') temp=2;
		else temp=3;
		if(curr->child[temp]== NULL)
		{
			curr->child[temp]=new trienode();
		}
		curr->child[temp]->countn++;
		curr= curr->child[temp];
		maxx=max(maxx,(curr->countn * xx));
		xx++;
	}
	return maxx;;
}
void del(trienode* cur)
{
    for (int i = 0; i < 4; i++)
        if (cur->child[i])
            del(cur->child[i]);

    delete (cur);
}
int main()
{

	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		root=new trienode();
		int n;
		cin>>n;
		char str[52];
		int maxx=0;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			maxx=max(maxx,insert(str));
			maxx=max(maxx, (int)strlen(str));
		}
		del(root);
		cout<<"Case "<<k<<": "<<maxx<<endl;
	}
}
