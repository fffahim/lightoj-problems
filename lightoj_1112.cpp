#include<bits/stdc++.h>
using namespace std;
#define maxx 100005
int n;
int arr[maxx];
struct make
{
    int prop,sum;
} tree[3*maxx];
void build(int i, int b, int e)
{
    if(b==e)
    {
        tree[i].sum=arr[b];
        return;
    }
    int left = i *2;
    int right = left+1;
    int mid= (b+e)/2;
    build(left,b,mid);
    build(right,mid+1, e);
    tree[i].sum= tree[left].sum + tree[right].sum;
}
void update(int i, int b, int e, int l, int r, int x)
{
    if( l>e || r<b ) return;
    if( b>=l && e<=r)
    {

        tree[i].sum+=x;

        return;
    }
    int left = i*2;
    int right= left +1;
    int mid = (b+e)/2;
    update(left,b,mid,l,r,x);
    update(right,mid+1,e,l,r,x);
    tree[i].sum = tree[left].sum + tree[right].sum;
}
int que(int i, int b, int e, int l, int r)
{
    if(l>e || r<b ) return 0;
    if(b>=l && e<=r)
    {
        return tree[i].sum;
    }
    int left= i*2;
    int right= left+1;
    int mid=(b+e)/2;
    int p=que(left,b,mid,l,r);
    int q=que(right,mid+1,e,l,r);
    return p+q ;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {   memset(tree,0,sizeof(tree));
        int q;
        scanf("%d %d", &n, &q);
        for(int j=0;j<n;j++)
        {
            scanf("%d", &arr[j]);
        }
        build(1,0,n-1);
        printf("Case %d:\n", i);
        while(q--)
        {
            int choice;
            scanf("%d", &choice);
            if(choice == 1)
            {
                int index;
                scanf("%d", &index);
                printf("answer :%d\n", arr[index]);
                update(1,0,n-1,index,index,-arr[index]);
                arr[index]=0;
            }
            else if(choice==2)
            {
                int in,value;
                scanf("%d %d", &in, &value);
                update(1,0,n-1,in,in,value);
                arr[in]+=value;
            }
            else if(choice==3)
            {
                int l, r;
                scanf("%d %d", &l, &r);
                printf("answer: %d\n",que(1,0,n-1,l,r));
            }
        }
    }
}
