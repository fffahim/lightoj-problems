#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100005];
int arr[100005],par[100005],fin[100005][35],level[100005];
void dfs(int from, int u, int lev)
{
    par[u] = from;
    level[u] = lev;
    for(int i=0;i<vec[u].size();i++)
    {
        if(vec[u][i]==from) continue;
        dfs(u,vec[u][i],lev+1);
    }
    return;
}
void lca(int n)
{
    memset(fin, -1, sizeof(fin));
    for(int i=0;i<n;i++) fin[i][0] = par[i];
    for(int j=1; 1<<j < n ; j++)
    {
        for(int i=1;i<n;i++)
        {
            if(fin[i][j-1] !=-1)
            {
                fin[i][j] = fin[fin[i][j-1]][j-1];
            }
        }
    }
}
int query(int u, int val)
{
    int temp=u;
    int flag=1;
    while(1)
    {
        if(1<<(flag+1) > level[u]) break;
        flag++;
    }
    for(int i=flag;i>=0;i--)
    {
        //cout<<fin[temp][i]<<endl;
        if(fin[temp][i]!=-1 ) 
        {
            if(arr[fin[temp][i]]>=val)  
            {
                //cout<<"val "<<arr[fin[temp][i]]<<endl;
                temp = fin[temp][i];
            }
        }
    }
    return temp;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;tt++)
    {
        int n,q;
        scanf("%d %d", &n, &q);
        arr[0] = 1;
        for(int i=1;i<n;i++)
        {
            int p,s;
            scanf("%d %d", &p, &s);
            vec[p].push_back(i);
            arr[i] = s;
        }
        dfs(0,0,0);
        lca(n);
        printf("Case %d:\n",tt);
        for(int i=0;i<q;i++)
        {
            int u,val;
            scanf("%d %d", &u, &val);
            printf("%d\n",query(u,val));
        }
        for(int i=0;i<=n;i++) vec[i].clear();
    }
}