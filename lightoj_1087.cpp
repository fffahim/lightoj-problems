#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int arr[200000],seg[4*200000],n;
void build(int curr, int l,int r)
{
    if(l==r)
    {
        if(l<=n) seg[curr]=1;
        else seg[curr]=0;
        return;
    }
    int left= curr*2;
    int right= left+1;
    int mid=(l+r)/2;
    build(left,l,mid);
    build(right,mid+1,r);
    seg[curr]=seg[left]+seg[right];
    return;

}
void update(int curr,int l,int r,int pos,int val)
{
    if(l==r)
    {
        // cout<<"l "<<l<<endl;
        seg[curr]=val;
        return;
    }
    int left= curr*2;
    int right= left+1;
    int mid=(l+r)/2;
    if(pos>=l && pos<=mid) update(left,l,mid,pos,val);
    else if(pos>=mid+1 && pos<=r) update(right,mid+1,r,pos,val);
    seg[curr]=seg[left]+seg[right];
    return;
}
int query(int curr,int l,int r,int sum,int tar)
{
    if(l==r)
    {
        int ans=arr[l];
        update(1,1,160000,l,0);
        return ans;
    }
    int left= curr*2;
    int right= left+1;
    int mid=(l+r)/2;
    if(sum+seg[left]>=tar)
    {
        return query(left,l,mid,sum,tar);
    }
    else
    {
        sum+=seg[left];
        return query(right,mid+1,r,sum,tar);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;tt++)
    {
        int qq;
        scanf("%d %d", &n, &qq);
        for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
        build(1,1,160000);
        char ch;
        int xx;
        printf("Case %d:\n",tt);
        for(int i=0;i<qq;i++)
        {
            
            cin>>ch>>xx;
            if(ch=='c')
            {
                if(seg[1]<xx) cout<<"none\n";
                else cout<<query(1,1,160000,0,xx)<<endl;
            }
            else
            {
                n++;
                arr[n]=xx;
                update(1,1,160000,n,1);
                
            }
            //cout<<"p"<<i<<endl;
        }
    }
}
