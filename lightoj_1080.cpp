#include<bits/stdc++.h>
#define maxx 100005
using namespace std;
char str[maxx];
int ans;
struct make{
  int sum,prop;
}tree[maxx * 3];
void build(int start, int endn, int node)
{
    if(start == endn)
    {
        tree[node].sum = str[start] - '0';
        return;
    }
    int mid = (start + endn)/2;
    int left = node * 2;
    int right = left +1;
    build(start,mid,left);
    build(mid+1, endn, right);
   // tree[node].sum = tree[left].sum + tree[right].sum;
}
void update(int node, int start, int endn, int s, int f)
{
    if( start > f || endn < s) return;
    if( start >= s && endn <= f)
    {
        tree[node].prop+=1;
        return;
    }
    int mid = (start + endn)/2;
    int left = node * 2;
    int right = left +1;
    update(left,start,mid,s,f);
    update(right, mid+1, endn,s,f);

}
void query(int node, int start, int endn, int p, int countn)
{
    if(start > p || endn < p) return ;
   if(start == p && endn == p)
   {    //cout<<tree[node].prop<<endl;
       if((countn+tree[node].prop)%2==0) ans= tree[node].sum;
       else
       {
          if(tree[node].sum == 1) ans=0;
          else ans=1;
       }
       return ;
   }
   int mid= (start + endn)/2;
   int left = node * 2;
   int right = left + 1;
   query(left, start, mid, p, countn+tree[node].prop);
   query(right, mid+1, endn, p, countn+tree[node].prop);

}
int main()
{
    int t,q;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {   ans=0;
        scanf("%s ", &str);
        int l=strlen(str)-1;
        memset(tree, 0, sizeof(tree));
        build (0,l,1);
        scanf("%d", &q);
        printf("Case %d:\n", i);
        for(int j=0;j<q;j++)
        {
            char ch[2];
            scanf("%s", &ch);
            if(ch[0]=='I')
            {   int s,f;
                scanf("%d %d", &s, &f);
                update(1,0,l,s-1,f-1);
            }
            else
            {
                int m;
                scanf("%d", &m);
                query(1,0,l,m-1,0);
                printf("%d\n", ans);
            }
        }

    }
}
