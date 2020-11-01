#include<bits/stdc++.h>
using namespace std;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int r,c;
char str[205][205];
int arr[205][205],vis[205][205],vis2[205][205];
deque<pair<int,int>>se;
int dfs2(int x,int y,int mark)
{
    deque<pair<int,int>>de;
    pair<int,int>p;
    p.first=x;
    p.second=y;
    de.push_back(p);
    vis[x][y]=0;
    while(!de.empty())
    {
        pair<int,int>pi;
        pi=de.front();
        de.pop_front();
        int xx=pi.first;
        int yy=pi.second;
        for(int i=0;i<4;i++)
        {
            int tx=xx+fx[i];
            int ty=yy+fy[i];
            if(tx<0 || tx>=r || ty<0 || ty>=c) return vis[xx][yy]+1;
            if(vis[tx][ty]==-1 && arr[tx][ty]>vis[xx][yy]+1)
            {
                vis[tx][ty]=vis[xx][yy]+1;
                de.push_back(make_pair(tx,ty));
            }
        }
    }
    return -1;
}
void dfs()
{
    while(!se.empty())
    {
        pair<int,int>p;
        p=se.front();
        se.pop_front();
        int xx=p.first;
        int yy=p.second;
        for(int i=0;i<4;i++)
        {
            int tx=xx+fx[i];
            int ty=yy+fy[i];
            if(tx>=0 && tx<r && ty>=0 && ty<c && arr[tx][ty]>arr[xx][yy]+1)
            {
                arr[tx][ty]=arr[xx][yy]+1;
                se.push_back(make_pair(tx,ty));
            }
        }
    }
}
int main()
{
    //  freopen("hacki.txt","r",stdin);
    // freopen("hacko.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int j=1;j<=t;j++)
    {
        scanf("%d %d", &r,&c);
        for(int i=0;i<205;i++)
        {
            for(int x=0;x<205;x++)
            {
                arr[i][x]=100000008;
                vis2[i][x]=-1;
                vis[i][x]=-1;
            }
        }
        for(int i=0;i<r;i++) cin>>str[i];
        int posx,posy,bx,by,flag=0;
        for(int i=0;i<r;i++)
        {
            for(int x=0;x<c;x++)
            {
                if(str[i][x]=='J')
                {
                    posx=i;
                    posy=x;
                }
                if(str[i][x]=='F')
                {
                    arr[i][x]=0;
                    se.push_back(make_pair(i,x));
                }
                if(str[i][x]=='#') arr[i][x]=-1;
            }
        }
        dfs();
        int an=dfs2(posx,posy,0);
        cout<<"Case "<<j<<": ";
        if(an==-1) printf("IMPOSSIBLE\n");
        else printf("%d\n",an);
    }
}