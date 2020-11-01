#include <bits/stdc++.h>
using namespace std;
#define infinity 25000
int dist[10000];
struct node{
    int u;
    int cost;
    node(int _u, int _cost){
        u = _u;
        cost = _cost;
    }
    bool operator < ( const node& p ) const {      return cost > p.cost;   } //Operator overloading    
};
void dijstkra(int n, vector<int>g[], vector<int>cost[], int source){
 
    for(int i=0;i<=n;i++) {
        dist[i] = infinity;
    }      
    priority_queue<node>q;
    q.push(node(source,0));
    dist[source] = 0;
    while(!q.empty()){
        node top = q.top();
        q.pop();
        int u=top.u;
        for(int i=0;i<(int)g[u].size();i++){
            int v=g[u][i];
            int maxx=max(dist[u],cost[u][i]);
            if(dist[v]>maxx)
            {
                dist[v]=maxx;
                q.push(node(v,dist[v]));
            }
            }
        }
}
int main()
{
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>g[10000], cost[10000];
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int source;
        cin>>source;
        dijstkra(n, g, cost, source);
        cout<<"Case "<<j<<":"<<endl;
        for(int i=0;i<n;i++)
        {
            if(dist[i]==infinity) cout<<"Impossible\n";
            else cout<<dist[i]<<endl;
        }
    }
}