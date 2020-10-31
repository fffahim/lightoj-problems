#include<bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, w;
};
bool cmp1(edge a,edge b)
{
   return a.w<b.w;  
}
bool cmp2( edge a,edge b)
{
  return  a.w>b.w;  
}
int pr[150];
vector<edge> e;
int find(int r)
{
    return (pr[r] == r) ? r : find(pr[r]);
}
int mst(int n,int mark)
{
    if(mark==0) sort(e.begin(), e.end(),cmp1);
    else sort(e.begin(), e.end(),cmp2);
    for (int i = 0; i <= n; i++)
        pr[i] = i;
    int count = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            pr[u] = v;
            count++;
            s += e[i].w;
            if (count == n )
                break;
        }
    }
    return s;
}
int main()
{
 
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        while(1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if(u==0 && v==0 && w==0) break;
            edge ed;
            ed.u=u;
            ed.v=v;
            ed.w=w;
            e.push_back(ed);
        }
        cout<<"Case "<<i<<": ";
        long long int sum1=mst(n,1);
        long long int sum2=mst(n,0);
        sum1+=sum2;
        if(sum1%2==0) cout<<sum1/2<<endl;
        else cout<<sum1<<"/2"<<endl;
        e.clear();
    }
}