#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
int seg[mx*3];
int print[mx];
void init(int node, int start, int finish)
{
    if(start==finish)
    {
        seg[node]=arr[start];
        return;
    }
    int left= node*2;
    int right= node*2 +1;
    int mid= (start + finish)/2;
    init(left,start,mid);
    init(right,mid+1,finish);
    seg[node]=min(seg[left], seg[right]);


}
int query(int node,int start,int finish,int a,int b)
{
   if(a>finish|| b<start) return mx;
   if(a<=start && b>=finish) return seg[node];
   int left= node*2;
   int right= node*2 +1;
   int mid= (start+finish) /2;
   int p1=query(left,start,mid,a,b);
   int p2=query(right,mid+1,finish,a,b);
   //cout<<p1<< p2;
   return min(p1,p2);

}
int main()
{
    int t;
    scanf("%d", &t);
    printf("\n");
    for(int i=1;i<=t;i++)
    {
        int n,q;
        scanf("%d %d", &n, &q);
        for(int j=1;j<=n;j++)
        scanf("%d", &arr[j]);
        init(1,1,n);
        printf("Case %d:\n",i);
        for(int k=0;k<q;k++)
        {   int a,b;
            scanf("%d %d", &a, &b);
            printf("%d\n",query(1,1,n,a,b));

        }

    }
}
