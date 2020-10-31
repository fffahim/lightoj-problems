#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,dis[10005][15];
struct node{
    int u,w,ta;
    node(int _w,int _u,int _ta)
    {
        u=_u;
        w=_w;
        ta=_ta;
    }
    bool operator < ( const node& p ) const {      return w > p.w;   }
};
vector<node>vec[10005];
void djkstra()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=14;j++) dis[i][j]=1e7+5;
    }
    dis[0][0]=0;
    queue<node>p;
    p.push(node(0,0,0));
    while(!p.empty())
    {
        int u = p.front().u;
        int w= p.front().w;
        int ta = p.front().ta;
        p.pop();
        for(int i=0;i<vec[u].size();i++)
        {
            if(ta+vec[u][i].ta<=d)
            {
                int temp=ta+vec[u][i].ta;
                if(dis[vec[u][i].u][temp]>w+vec[u][i].w)
                {
                    dis[vec[u][i].u][temp]=w+vec[u][i].w;
                    p.push(node(dis[vec[u][i].u][temp],vec[u][i].u,temp));
                }
            }
        }
    }
}
int main()
{
    //  freopen("hacki.txt","r",stdin);
    // freopen("hacko.txt","w",stdout);
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        cin>>n>>m>>k>>d;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vec[u].push_back(node(w,v,0));
        }
        for(int i=0;i<k;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vec[u].push_back(node(w,v,1));
        }
        djkstra();
        int ans=1e7+5;
        for(int i=0;i<=d;i++)
        {
            ans=min(ans,dis[n-1][i]);
        }
        cout<<"Case "<<x<<": ";
        if(ans!=1e7+5) cout<<ans<<endl;
        else cout<<"Impossible\n";
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
        }
    }
}