#include<bits/stdc++.h>
using namespace std;
int k;
struct trienode{
	int countn;
	trienode * child[2];
	trienode()
	{
		countn=0;
		for(int i=0;i<2;i++) child[i]=NULL;
	}
}* root;
void insert(int p)
{
	trienode* curr = root;
	for(int i=30;i>=0;i--)
	{
		bool bit = bool (p&(1<<i));
		if(curr->child[bit]==NULL)
		{
			curr->child[bit]=new trienode();
		}
		curr=curr->child[bit];
	}
	curr->countn=p;
	return;
}
int searchtrie(int p)
{
	trienode* curr = root;
	for(int i=30;i>=0;i--)
	{
		bool currbit=bool(p&(1<<i));
		if(curr->child[!currbit]!=NULL)
		{
			curr=curr->child[!currbit];
		}
		else curr= curr->child[currbit];
	}
	return (curr->countn)^p;

}
int searchmin(int p)
{
	trienode* curr = root;
	for(int i=30;i>=0;i--)
	{
		bool currbit=bool(p&(1<<i));
		if(curr->child[currbit]!=NULL)
		{
			curr=curr->child[currbit];
		}
		else curr= curr->child[!currbit];
	}
	return (curr->countn)^p;

}
void del(trienode* cur)
{
    for (int i = 0; i < 2; i++)
        if (cur->child[i])
            del(cur->child[i]);
    delete(cur);
}
int main()
{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		int n;
		cin>>n;
		int p=0;
		root=new trienode();
		insert(0);
		int ans=0,minn=10000007;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			p^=temp;
			minn=min(minn,searchmin(p));
			ans=max(ans,searchtrie(p));
			insert(p);
		}
		del(root);
		cout<<"Case "<<tt<<": "<<ans<<" "<<minn<<endl;
		
	}
}
