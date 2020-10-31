#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,w;
    node(int _u,int _w)
    {
        u=_u;
        w=_w;
    }
};
int dis1[10000],dis2[10000],n;
vector<int>vec[10000],cost[10000];
int djkstra(int s,int c)
{
    for(int i=0;i<=n;i++)
    {
        dis1[i]=100000005;
        dis2[i]=100000005;
    }
    dis1[1]=0;
    set<pair<int,int>>p;
    p.insert({s,0});
    while(!p.empty())
    {
        int x1=p.begin()->first;
        int w1=p.begin()->second;
        p.erase(p.begin());
        for(int i=0;i<vec[x1].size();i++)
        {
            int x2=vec[x1][i];
            int weight=cost[x1][i];
            if(dis1[x2]>w1+weight)
            {
                p.erase({x2,dis1[x2]});
                p.erase({x2,dis2[x2]});
                dis2[x2]=dis1[x2];
                dis1[x2]=w1+weight;
                p.insert({x2,dis1[x2]});
                p.insert({x2,dis2[x2]});
            }
            else if(dis1[x2]<w1+weight && dis2[x2]>w1+weight)
            {
                p.erase({x2,dis2[x2]});
                dis2[x2]=w1+weight;
                p.insert({x2,dis2[x2]});
            }
        }
    }
    return dis2[n];
}
int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int r;
        cin>>n>>r;
        for(int i=0;i<r;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vec[u].push_back(v);
            vec[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        cout<<"Case "<<k<<": ";
        cout<<djkstra(1,0)<<endl;
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
            cost[i].clear();
        }
    }
}