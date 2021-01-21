#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>vec[1000005];
int mark[1000005];
int dfs(int i)
{
	for(int x=0;x<=n;x++)
	{
		mark[x]=0;
	}
	deque<int>de;
	de.push_back(i);
	mark[i]=1;
	int sum=0;
	while(!de.empty())
	{
		int temp= de.front();
		de.pop_front();
		int par= mark[temp];
		for(int j=0;j<vec[temp].size();j++)
		{
			if(mark[vec[temp][j]]==0)
			{
				mark[vec[temp][j]]=par+1;
				sum=max(sum,mark[vec[temp][j]]);
				de.push_back(vec[temp][j]);
			}
		}
	}
	return sum;
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n-1;i++) 
	{
		int x,y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	deque<int>de;
	for(int i=1;i<=n;i++)
	{
		int xx= dfs(i);
		if(xx==0) xx++;
		printf("%d\n",xx);
	}
}