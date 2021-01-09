#include<bits/stdc++.h>
using namespace std;
int value[100005],check[100005];
vector<int>vec[100005];
pair<int,int> bfs(int x)
{
    check[x]=1;
    int sum=value[x],countn=1;
    pair<int,int>temp;
    for(int i=0;i<vec[x].size();i++)
    {
        if(check[vec[x][i]]==-1)
        {
            temp= bfs(vec[x][i]);
            sum+= temp.first;
            countn+= temp.second;
        }
    }
    return make_pair(sum,countn);
}
int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>value[i];
            check[i]=-1;
            vec[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        int flag=0,temp=-1;
        for(int i=1;i<=n;i++)
        {
            pair<int,int>p;
            if(check[i]==-1)
            {
                p=bfs(i);
                if(p.first % p.second !=0)
                {
                    flag=1;
                    break;
                }
                if(temp==-1) temp= p.first/p.second;
                if(p.first/p.second!= temp)
                {
                    flag=1;
                    break;
                }
            }
        }
        cout<<"Case "<<k<<": ";
        if(flag==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
}