#include<bits/stdc++.h>
using namespace std;
int arr[550],n,m,s;
vector<int>vec[550],cost[550];
int dp[550][20],check[550][550];
struct node{
    int u,w,ghursi;
    node(int _u,int _w,int _ghursi)
    {
        u=_u;
        w=_w;
        ghursi=_ghursi;
    }
    bool operator < ( const node& p ) const {      return w > p.w;   }
};
void djkstra()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=15;j++) dp[i][j]=1e8+5;
    }
    priority_queue<node>p;
    if(arr[0]==1)
    {
        dp[0][1]=0;
        p.push(node(0,0,1));
    }
    else
    {
        dp[0][0]=0;
        p.push(node(0,0,0));
    }
    while(!p.empty())
    {
        int u=p.top().u;
        int cos=p.top().w;
        int ghursi=p.top().ghursi;
        p.pop();
        for(int i=0;i<vec[u].size();i++)
        {
            int v= vec[u][i];
            if(check[u][v]==-1)
            {
                check[u][v]=0;
                int vw= cost[u][i]+cos;
                int vghursi= ghursi+arr[v];
                if(vghursi>s) vghursi=s;
                if(dp[v][vghursi]> vw )
                {
                    dp[v][vghursi]=vw;
                    p.push(node(v,vw,vghursi));
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
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d %d %d", &n, &m, &s);
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
            cost[i].clear();
            arr[i]=0;
            for(int j=0;j<=n;j++) check[i][j]=-1;
        }
        for(int i=0;i<s;i++)
        {
            int x;
            cin>>x;
            arr[x]=1;
        }
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vec[u].push_back(v);
            cost[u].push_back(w);
        }
        djkstra();
        int flag=0;
        cout<<"Case "<<k<<": ";
        for(int i=s;i>=0;i--)
        {
            if(dp[n-1][i]!=1e8+5)
            {
               cout<<i<<" "<<dp[n-1][i]<<endl;
               flag=1;
               break;
            }
        }
        if(flag==0) cout<<"Impossible\n";
    }
}