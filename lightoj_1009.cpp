#include<bits/stdc++.h>
using namespace std;
int color[100005];

int bfs(int u,vector<int>vec[20000])
{

    int black=0,total=0;
    deque<int>de;
    de.push_back(u);
    color[u]=1;
    while(!de.empty())
    {
        total++;
        int temp = de.front();
        if(color[temp]==1) black++;
        de.pop_front();
        for(int i=0;i<vec[temp].size();i++)
        {
            if(color[vec[temp][i]]==-1)
            {

            if(color[temp]==0)
            {
                color[vec[temp][i]]=1;
            }
            else
            {
                color[vec[temp][i]]=0;
            }
            de.push_back(vec[temp][i]);
            }
        }

    }
    return max(black,total-black);

}
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        vector<int>vec[20005];
         set <int, greater <int> > ele;
         set <int, greater <int> > :: iterator itr;
        int n,tot=0;
        scanf("%d", &n);
        memset(color,-1,sizeof(color));

        for(int j=0;j<n;j++)
        {
            int u,v;
            scanf("%d %d", &u, &v);
            ele.insert(u);
            ele.insert(v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for(itr=ele.begin();itr!=ele.end();itr++)
        {
            if(color[*itr]==-1)
            {
                tot+=bfs(*itr,vec);
            }
        }
        cout<<"Case "<<i<<": "<<tot<<endl;
    }
}
