#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char cell[205][205];
int d[205][205],vis[205][205];
int row,col;
int bfs(int sx,int sy)
{
    int total=1;
	memset(vis,0,sizeof (vis));
	vis[sx][sy]=1;
	queue<pii>q;
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k];
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!='#' and vis[tx][ty]==0)
			{
				vis[tx][ty]=1;
				total++;
				q.push(pii(tx,ty));
			}
		}
	}
	return total;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        int sx,sy;
        char str[205];
        scanf("%d %d", &col, &row);
        for(int j=0;j<row;j++)
        {
            scanf("%s", str);
            for(int k=0;k<col;k++)
            {
                cell[j][k]=str[k];
                if(str[k]=='@')
                {
                    sx=j;
                    sy=k;
                }
            }
        }
        cout<<"Case "<<i<<": "<<bfs(sx,sy)<<endl;
    }
}
