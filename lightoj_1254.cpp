#include<bits/stdc++.h>
using namespace std;
int arr[150],c,n;
vector<int>vec[150],cost[150];
int dp[150][150];
struct node{
    int u,w,baki;
    node(int _u,int _w,int _baki)
    {
        u=_u;
        w=_w;
        baki=_baki;
    }
    bool operator < ( const node& p ) const {      return w > p.w;   }
};
int djkstra(int start,int end)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++) dp[i][j]=1e8+5;
    }
    priority_queue<node>p;
    dp[start][0]=0;
    p.push(node(start,0,0));
    while(!p.empty())
    {
        int u=p.top().u;
        int cos=p.top().w;
        int baki=p.top().baki;
        p.pop();
        if(u==end) return cos;
        for(int j=0;j<=c-baki;j++)
        {
            for(int i=0;i<vec[u].size();i++)
            {
                int v=vec[u][i];
                int dorker= cost[u][i];
                if(baki+j<dorker) continue;
                if(dp[v][baki+j-dorker]>cos+(j*arr[u]) )
                {
                    dp[v][baki+j-dorker]=cos+(j*arr[u]);
                    p.push(node(v,dp[v][baki+j-dorker],baki+j-dorker));
                }
            }
        }      
    }
    return 1e8+5;
}
int main()
{
    //  freopen("hacki.txt","r",stdin);
    // freopen("hacko.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            vec[u].push_back(v);
            vec[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        printf("Case %d:\n",k);
        int q;
        scanf("%d", &q);
        while(q--)
        {
            int s,e;
            scanf("%d %d %d",&c,&s,&e);
            int ans=djkstra(s,e);
            if(ans<1e8+5) printf("%d\n",ans);
            else printf("impossible\n");
        }
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
            cost[i].clear();
        }
    }
}