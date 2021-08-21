#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100005],cost[100005];
int sparent[100005][32], svalue[100005][32], level[100005], maxxval[100005],pr[100005];
int logg;
struct node{
    int u,v;
    long long int cost;
    node(int _u, int _v, long long int _cost){
        u = _u;
        v = _v;
        cost = _cost;
    }
    bool operator < ( const node& p ) const {      return cost < p.cost;   } 
    
};
vector<node>fin;
void build(int src,int n)
{
    memset(sparent, -1, sizeof(sparent));
    memset(level,-1, sizeof(level));
    deque<int>de;
    de.push_back(src);
    level[src]=0;
    while(!de.empty())
    {
        int u = de.front();
        de.pop_front();
        for(int i=0;i<vec[u].size();i++)
        {
           if(level[vec[u][i]]==-1)
           {
                level[vec[u][i]] = level[u]+1;
                sparent[vec[u][i]][0] = u;
                svalue[vec[u][i]][0] = cost[u][i]; 
                de.push_back(vec[u][i]);
                //cout<<"val "<<u<<" "<<vec[u][i]<<" "<<svalue[vec[u][i]][0]<<endl;
           }
            //cout<<"val "<<svalue[vec[u][i]][0]<<endl;
        }
    }
}
void sparse(int n)
{
    //memset(sparent, -1, sizeof(sparent));
    logg = 1;
    while(1)
    {
        int next = logg + 1;
        if(1<<next > n) break;
        logg++;
    }
    for(int i=1;i<=logg;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(sparent[j][i-1]!=-1)
            {
                sparent[j][i] = sparent[sparent[j][i-1]][i-1];
                svalue[j][i] = max(svalue[sparent[j][i-1]][i-1], svalue[j][i-1]);
            }
        }
    }
    return;
}
int lca(int u, int v)
{
    logg =1;
    if(level[v]>level[u]) swap(u,v);
    while(1)
    {
        int next = logg + 1;
        if(1<<next > level[u]) break;
        logg++;
    }
    for(int i=logg;i>=0;i--)
    {
        if(level[u] - (1<<i) >= level[v]) u = sparent[u][i];
    }
    if(u==v) return u;
    for(int i=logg;i>=0;i--)
    {
        if(sparent[u][i]!=-1)
        {
            if(sparent[u][i] != sparent[v][i])
            {
                u = sparent[u][i];
                v = sparent[v][i];
            }
        }
    }
    return sparent[u][0];
}
int query(int root, int u)
{
    int ans = 0;
    //cout<<root<<" "<<u<<endl;
    for(int i=logg;i>=0;i--)
    {
        if(level[u] - (1<<i) >= level[root])
        {
            //cout<<svalue[u][i]<<endl;
            ans = max(ans,svalue[u][i]);
            u = sparent[u][i];
        }
    }
    return ans;
}
int find(int i)
{
    if(pr[i]==i) return i;
    return pr[i] = find(pr[i]);
}
void spantree(int n)
{
    for(int i=1;i<=n;i++) pr[i] = i;
    int countn =0;
    for(int i=0;i<fin.size();i++)
    {
        int u = find(fin[i].u);
        int v = find(fin[i].v);
        if(u!=v)
        {
            pr[v]=u;
            countn++;
            vec[fin[i].u].push_back(fin[i].v);
            vec[fin[i].v].push_back(fin[i].u);
            cost[fin[i].u].push_back(fin[i].cost);
            cost[fin[i].v].push_back(fin[i].cost);
        }
        if(countn==n-1) break;
    }
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;tt++)
    {
        int n,m;
        scanf("%d %d", &n, &m);
        for(int i=0;i<m;i++)
        {
            int u, v , val;
            scanf("%d %d %d", &u, &v, &val);
            fin.push_back(node(u,v,val));
        }
        sort(fin.begin(),fin.end());
        // for(int i=0;i<fin.size();i++)
        // {
        //     cout<<fin[i].cost<<" ";
        // }
        // cout<<endl;
        spantree(n);
        build(1,n);
        sparse(n);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n",tt);
        while(q--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            int root = lca(u,v);
            //cout<<root<<endl;
            int ans = max(query(root,u), query(root,v));
            printf("%d\n",ans);
        }
        for(int i=0;i<=n;i++)
        {
            vec[i].clear();
            cost[i].clear();
        }
        fin.clear();
    }
}
