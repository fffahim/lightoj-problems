#include<bits/stdc++.h>
using namespace std;
int arr[150][150],vis[150];
vector<int>vec[150];
int dfs(int i)
{
    vis[i]=1;
    int ans=0,flag=0;
    for(int x=0;x<vec[i].size();x++)
    {
        if(vis[vec[i][x]]==0)
        {
            flag=1;
            if(arr[i][vec[i][x]]==0) ans+=arr[vec[i][x]][i];
            ans+=dfs(vec[i][x]);
        }
    }
    if(flag==0)
    {
        if(arr[i][1]==0) ans+=arr[1][i];
    }
    return ans;
}
int main()
{
    // freopen("hacki.txt","r",stdin);
    // freopen("hacko.txt","w",stdout);
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int u,v,x;
            cin>>u>>v>>x;
            vec[u].push_back(v);
            vec[v].push_back(u);
            arr[u][v]=x;
        }
        int fin=100000005;
        vis[1]=1;
        for(int i=0;i<vec[1].size();i++)
        {
            int ans=0;
            if(arr[1][vec[1][i]]==0) ans+=arr[vec[1][i]][1];
            ans+=dfs(vec[1][i]);
            fin=min(fin,ans);
            for(int k=2;k<=n;k++) vis[k]=0;
        }
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
            for(int x=0;x<=n;x++) arr[i][x]=0;
        }
        cout<<"Case "<<j<<": ";
        cout<<fin<<endl;
    }
}