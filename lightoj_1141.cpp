#include<bits/stdc++.h>
using namespace std;
int p[1005],visit[1005],val[1005];
vector<int>de,pf[1005];
void prime()
{
    for(int i=4;i<=1005;i+=2) p[i]=0;
    for(int i=3;i*i<=1005;i+=2)
    {
        if(p[i]==-1)
        {
            for(int j=i*i;j<=1005;j+=2*i) p[j]=0;
        }
    }
    for(int i=2;i<1005;i++)
    {
        if(p[i]==-1) de.push_back(i);
    }
}
int bfs(int a, int b)
{
    deque<int>deq;
    deq.push_back(a);
    visit[a]=1;
    while(!deq.empty())
    {
        int x= deq.front();
        //cout<<x<<endl;
        deq.pop_front();
        if(x==b)
        {
            //cout<<deq.front()<<" "<<val[x];
            return val[x];
        }
        for(int i=0;i<pf[x].size();i++)
            {
             int v = x+pf[x][i];
        if(visit[v]!=1 && v<=b)
        {
            deq.push_back(v);
            visit[v]=1;
            val[v]=val[x]+1;
        }
            }

    }
    return -1;
}
void fact()
{
    for(int i=2;i<1005;i++)
    {
        int te =i;
        int sq = sqrt(te);
        for(int j=0;j<de.size() && de[j]<=sq;j++ )
        {
            if(te%de[j]==0)
            {
                pf[i].push_back(de[j]);
                while(te%de[j]==0) te/=de[j];
            }
        }
        if(te!=1 && te!=i) pf[i].push_back(te);
    }
}
int main()
{
    memset(p,-1,sizeof(p));

    prime();
    fact();
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        memset(visit,-1,sizeof(visit));
         memset(val,0,sizeof(val));
        int a, b;
        scanf("%d %d", &a, &b);
        cout<<"Case "<<i<<": "<<bfs(a,b)<<endl;
    }
}
