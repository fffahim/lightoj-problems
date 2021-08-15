#include<bits/stdc++.h>
using namespace std;
int n, arr[100005],level[100005],par[100005], fin[100005][25];
int start[100005],finish[100005],ti, brr[200005], seg[400005];
vector<int>vec[100005];
void dfs(int from, int u,int lev)
{
    level[u] = lev;
    par[u] = from ;
    start[u] = ti+1;
    brr[ti+1] = arr[u];
    ti++;
    for(int i=0;i<vec[u].size();i++)
    {
        int v = vec[u][i];
        if( v == from) continue;
        dfs(u,v,lev+1);
    }
    finish[u] = ti + 1;
    brr[ti+1] = (arr[u] * -1);
    ti++;
    return;
}
void init(int curr, int i, int j)
{
    if(i==j)
    {
        seg[curr] = brr[i];
        return;
    }
    int left = curr * 2;
    int right = left + 1;
    int mid = (i+j)/2;
    init(left,i,mid);
    init(right,mid+1,j);
    seg[curr] = seg[left] + seg[right];
    return;
}
void update(int curr, int i, int j, int l, int val)
{
    if(i>l || j<l) return;
    if(i>=l && j<=l)
    {
        seg[curr] = val;
        return;
    }
    int left = curr * 2;
    int right = left + 1;
    int mid = (i+j)/2;
    update(left,i,mid,l,val);
    update(right,mid+1,j,l , val);
    seg[curr] = seg[left] + seg[right];
    return;
}
int query(int curr, int i, int j, int l, int r)
{
    if(r<i || l>j) return 0;
    if(i>=l && j<=r)
    {
        return seg[curr];
    }
    int left = curr * 2;
    int right = left + 1;
    int mid = (i+j)/2;
    int p1 = query(left, i, mid, l, r);
    int p2 = query(right, mid+1, j, l, r);
    return p1 + p2;
}
void lca()
{
    memset(fin, -1, sizeof(fin));
    for(int i=0;i<n;i++)
    {
        fin[i][0] = par[i];
    }
    for(int j=1; 1<<j < n ;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(fin[i][j-1]!=-1)
            {
                fin[i][j] = fin[fin[i][j-1]][j-1];
            }
        }
    }
}
int getLca(int u, int v)
{
    int log,i;
    if(level[v]>level[u])
    {
        swap(u,v);
    }
    log=1;
    while(1)
    {
        int next = log + 1;
        if((1<<next) > level[u]) break;
        log++;
    }
    for(int j = log; j>=0;j--)
    {
        if(level[u] - (1<<j)>= level[v])
        {
            u = fin[u][j];
        }
    }
    if( u == v) return u;
    for(int j=log;j>=0;j--)
    {
        if(fin[u][j] != -1 && fin[u][j]!=fin[v][j])
        {
            u = fin[u][j];
            v = fin[v][j];
        }
    }
    return par[u];
}
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;tt++)
    {
        ti = 0;
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d", &arr[i]);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d %d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        dfs(0,0,0);
        init(1,1,ti);
        lca();
        int q;
        scanf("%d", &q);
        printf("Case %d:\n",tt);
        while(q--)
        {
            int x,u,v;
            scanf("%d %d %d", &x, &u, &v);
            if(x==0)
            {
                int root = getLca(u,v);
                int p1 = query(1,1,ti,start[root],start[u]);
                //cout<<"p "<<p1<<endl;
                p1 += query(1,1,ti,start[root],start[v]);
                //cout<<"p "<<p1<<endl;
                p1-= brr[start[root]];
                printf("%d\n",p1);
            }
            else
            {
                brr[start[u]] = v;
                brr[finish[u]] = -v;
                update(1,1,ti,start[u],v);
                update(1,1,ti,finish[u],-v);
            }
        }
        for(int i=0;i<=n;i++) vec[i].clear();
    }
}