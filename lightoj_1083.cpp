#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int arr[50000],seg[4*50000];
struct node{
    int val,flag;
    node(){}
    node(int _val,int _flag)
    {
        val=_val;
        flag=_flag;
    }
};
void build(int curr,int l,int r)
{
    if(l==r)
    {
        seg[curr]=arr[l];
        return;
    }
    int left= 2 * curr;
    int right= left+1;
    int mid= (l+r)/2;
    build(left,l,mid);
    build(right,mid+1,r);
    seg[curr]=min(seg[left],seg[right]);
    return;
}
node query1(int curr,int l,int r, int st,int en,int tar)
{
    if(r<l) return node(0,0);
    if(st>r || en<l) return node(0,1);
    if(l==r)
    {
        if(seg[curr]>=tar) return node(1,1);
        else return node(0,0);
    }
    int left= 2 * curr;
    int right= left+1;
    int mid= (l+r)/2;
    int sum=0;
    if(l>=st && r<=en)
    {
        if(seg[curr]>=tar) return node(r-l+1,1);
        else
        {
            node temp=query1(left,l,mid,st,en,tar);
            sum+= temp.val;
            if(temp.flag==1) 
            {
                temp=query1(right,mid+1,r,st,en,tar);
                sum+=temp.val;
            }
            if(temp.flag==1) return node(sum,1);
            else return node(sum,0);
        }
    }
    node temp=query1(left,l,mid,st,en,tar);
    sum+= temp.val;
    if(temp.flag==1) 
    {
        temp=query1(right,mid+1,r,st,en,tar);
        sum+=temp.val;
    }
    if(temp.flag==1) return node(sum,1);
    else return node(sum,0);


}
node query2(int curr,int l,int r, int st,int en,int tar)
{
    if(r<l) return node(0,0);
    if(st>r || en<l) return node(0,1);
    if(l==r)
    {
        if(seg[curr]>=tar) return node(1,1);
        else return node(0,0);
    }
    int left= 2 * curr;
    int right= left+1;
    int mid= (l+r)/2;
    int sum=0;
    if(l>=st && r<=en)
    {
        if(seg[curr]>=tar) return node(r-l+1,1);
        else
        {
            node temp=query2(right,mid+1,r,st,en,tar);
            sum+= temp.val;
            if(temp.flag==1) 
            {
                temp=query2(left,l,mid,st,en,tar);
                sum+=temp.val;
            }
            if(temp.flag==1) return node(sum,1);
            else return node(sum,0);
        }
    }
    node temp=query2(right,mid+1,r,st,en,tar);
    sum+= temp.val;
    if(temp.flag==1) 
    {
        temp=query2(left,l,mid,st,en,tar);
        sum+=temp.val;
    }
    if(temp.flag==1) return node(sum,1);
    else return node(sum,0);


}
int main()
{
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
        build(1,1,n);
        ll maxx=0;
        for(int i=1;i<=n;i++)
        {
            ll sum=1;
            node temp= query1(1,1,n,i+1,n,arr[i]);
            node temp2= query2(1,1,n,1,i-1,arr[i]);
            sum+=(temp.val+temp2.val);
            sum*=(ll(arr[i]));
            maxx=max(maxx,sum);
        }
        printf("Case %d: %lld\n",tt,maxx);
        
    }
    
}
