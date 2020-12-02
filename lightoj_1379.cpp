#include<bits/stdc++.h>
using namespace std;
long long int dis1[10005],dis2[10005];
vector<int>vec[10005],rev[10005],cost[10005],cost2[10005];
int n;
struct node{
    int u,w,tot;
    node(int _u,int _w,int _tot)
    {
        u=_u;
        w=_w;
        tot=_tot;
    }
    bool operator < ( const node& p ) const {      return w > p.w;   }
};
void djkstra1(int start)
{
    for(int i=1;i<=n;i++)
    {
        dis1[i]=5e9+5;
    }
    priority_queue<node>p;
    dis1[start]=0;
    p.push(node(start,0,0));
    while(!p.empty())
    {
        int u = p.top().u;
        int tot = p.top().tot;
        p.pop();
        for(int i=0;i<vec[u].size();i++)
        {
            int v = vec[u][i];
            int sum= tot + cost[u][i];
            if(dis1[v]>sum)
            {
                dis1[v]=sum;
                p.push(node(v,cost[u][i],dis1[v]));
            }
        }
    }
}
void djkstra2(int start)
{
    for(int i=1;i<=n;i++)
    {
        dis2[i]=5e9+5;
    }
    priority_queue<node>p;
    dis2[start]=0;
    p.push(node(start,0,0));
    while(!p.empty())
    {
        int u = p.top().u;
        int tot = p.top().tot;
        p.pop();
        for(int i=0;i<rev[u].size();i++)
        {
            int v = rev[u][i];
            int sum= tot + cost2[u][i];
            if(dis2[v]>sum)
            {
                dis2[v]=sum;
                p.push(node(v,cost2[u][i],dis2[v]));
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int kk=1;kk<=t;kk++)
    {
        int m,s,t,p;
        cin>>n>>m>>s>>t>>p;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vec[u].push_back(v);
            cost[u].push_back(w);
            rev[v].push_back(u);
            cost2[v].push_back(w);
        }
        djkstra1(s);
        djkstra2(t);
        int maxx=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                int v = vec[i][j];
                int cos =cost[i][j];
                if(dis1[i]+cos+dis2[v]<=p) maxx=max(maxx,cos);
            }
        }
        cout<<"Case "<<kk<<": "<<maxx<<endl;
        for(int i=1;i<=n;i++)
        {
            vec[i].clear();
            rev[i].clear();
            cost[i].clear();
            cost2[i].clear();
        }
    }

}