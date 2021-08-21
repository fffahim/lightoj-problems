#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100005],cost[100005];
int n, logg, level[100005], spar[100005][35], smaxxval[100005][35], sminnval[100005][35];
void bfs(int src)
{
    memset(level,-1,sizeof(level));
    memset(spar, -1, sizeof(spar));
    level[src]=0;
    deque<int>de;
    de.push_back(src);
    while(!de.empty())
    {
        int u = de.front();
        de.pop_front();
        for(int i=0;i<vec[u].size();i++)
        {
            if(level[vec[u][i]]==-1)
            {
                level[vec[u][i]] = level[u] + 1;
                spar[vec[u][i]][0] = u;
                smaxxval[vec[u][i]][0] = cost[u][i];
                sminnval[vec[u][i]][0] = cost[u][i];
                de.push_back(vec[u][i]); 
            }
        }
    }
}
void sparse(int src)
{
    logg = 1;
    while(1)
    {
        int next = logg+1;
        if(1<<next >n) break;
        logg++;
    }
    for(int i=1;i<=logg;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(spar[j][i-1] != -1)
            {
                spar[j][i] = spar[spar[j][i-1]][i-1];
                smaxxval[j][i] = max(smaxxval[j][i-1], smaxxval[spar[j][i-1]][i-1]);
                sminnval[j][i] = min(sminnval[j][i-1], sminnval[spar[j][i-1]][i-1]);
                // if(j==4 && i==1)
                // {
                //     cout<<"nn "<<smaxxval[j][i]<<" "<<sminnval[j][i]<<endl;
                // }
            }
        }
    }
}
int lca(int u, int v)
{
    if(level[u]<level[v]) swap(u,v);
    logg=1;
    while(1)
    {
        int next = logg+1;
        if(1<<next > level[u]) break;
        logg++;
    }
    for(int i=logg;i>=0;i--)
    {
        if(level[u] - (1<<i)>= level[v]) u = spar[u][i];
    }
    if(u==v) return u;
    for(int i=logg;i>=0;i--)
    {
        if(spar[u][i]!=-1)
        {
            if(spar[u][i] != spar[v][i])
            {
                u = spar[u][i];
                v = spar[v][i];
            }
        }
    }
    return spar[u][0];
}
pair<int,int> query(int root,int v)
{
    int maxx = 0, minn= 1e9;
    for(int i=logg;i>=0;i--)
    {
        if(level[v] - (1<<i) >= level[root])
        {
            maxx = max(maxx,smaxxval[v][i]);
            minn = min(minn,sminnval[v][i]);
            //if(v==4) cout<<smaxxval[v][i]<<" p "<<sminnval[v][i]<<endl;
            v = spar[v][i];
        }
    }
    return make_pair(maxx,minn);
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d", &n);
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            scanf("%d %d %d", &u, &v, &w);
            vec[u].push_back(v);
            vec[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        bfs(1);
        sparse(1);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n",tt);
        while(q--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            int root = lca(u,v);
            //cout<<root<<endl;
            pair<int,int>p1 = query(root,u);
            pair<int,int>p2 = query(root,v);
            printf("%d %d\n", min(p1.second,p2.second), max(p1.first,p2.first));
        }
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
            cost[i].clear();
        }
    }
    
}