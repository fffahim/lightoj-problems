#include<bits/stdc++.h>
using namespace std;
int n,r;
vector<int>vec[150];
int vis[150],countn[150];
deque<int>de;
void bfs(int s)
{
    vis[s]=0;
    deque<int>d;
    d.push_back(s);
    while(!d.empty())
    {
        int x=d.front();
        d.pop_front();
        int flag=0;
        for(int i=0;i<vec[x].size();i++)
        {
            if(vis[vec[x][i]]==-1)
            {
                flag=1;
                d.push_back(vec[x][i]);
                vis[vec[x][i]]=vis[x]+1;
            }
        }
        if(flag==0)
        {
            de.push_back(x);
            countn[x]=vis[x];
        }
    }
    return;
}
int bfs2(int s,int e)
{
    vis[s]=0;
    deque<int>d;
    d.push_back(s);
    while(!d.empty())
    {
        int x = d.front();
        d.pop_front();
        for(int i=0;i<vec[x].size();i++)
        {
            if(vis[vec[x][i]]==-1)
            {
                vis[vec[x][i]]=vis[x]+1;
                d.push_back(vec[x][i]);
            }
        }
 
    }
    return vis[e];
}
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        cin>>n>>r;
        for(int i=0;i<=n;i++)
        {
            countn[i]=0;
            vec[i].clear();
            vis[i]=-1;
        }
        for(int i=0;i<r;i++)
        {
            int u,v;
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        int s,e;
        cin>>s>>e;
        bfs(s);
        int maxx=0;
        while(!de.empty())
        {
            for(int i=0;i<=n;i++) vis[i]=-1;
            int x = de.front();
            de.pop_front();
            maxx=max(maxx,countn[x]+bfs2(x,e));
        }
        cout<<"Case "<<tt<<": "<<maxx<<endl;
       
    }
}