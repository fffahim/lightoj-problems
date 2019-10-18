#include<bits/stdc++.h>
using namespace std;
int sum[1005],vis[1005];
vector<int>vec[1005];
void bfs(int a)
{
    deque<int>de;
    de.push_back(a);
    sum[a]++;
    vis[a]=1;
    while(!de.empty())
    {
        int x = de.front();
        de.pop_front();
        for(int i=0;i<vec[x].size();i++)
        {
            if(vis[vec[x][i]]==0)
            {
                vis[vec[x][i]]=1;
                sum[vec[x][i]]++;
                de.push_back(vec[x][i]);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        memset(sum,0,sizeof(vis));
        int k,n,m,summ=0;
        scanf("%d %d %d", &k, &n,&m);
        int arr[k];
        for(int j=0;j<k;j++)
        {
            scanf("%d", &arr[j]);
        }
        for(int j=0;j<m;j++)
        {
            int u,v;
            scanf("%d %d", &u, &v);
            vec[u].push_back(v);
        }
        for(int j=0;j<k;j++)
        {
            memset(vis,0,sizeof(vis));
            bfs(arr[j]);
        }
        for(int j=1;j<=n;j++)
        {
            if(sum[j]==k) summ++;
        }
        cout<<"Case "<<i<<": "<<summ<<endl;
        for(int j=0;j<=n;j++) vec[j].clear();
    }
}
