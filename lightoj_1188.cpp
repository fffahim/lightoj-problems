#include<bits/stdc++.h>
using namespace std;
int n,q;
int arr[200005],ans[200005],check[200005],agrindex[200005],seg[4*100005];
struct node{
    int r,l,index;
    node(){}
    node(int _r, int _l,int _index)
    {
        r=_r;
        l=_l;
        index=_index;
    }
};
vector<node>vec;
bool cmp(node a,node b)
{
    if(a.r==b.r) return a.l<b.l;
    return a.r<b.r;
}
void update(int curr,int i,int j,int pos,int val)
{
    if(pos<i || pos>j) return;
    if(i==j && i==pos)
    {
        seg[curr]=val;
        return;
    }
    int left= 2 * curr;
    int right= left+1;
    int mid= (i+j)/2;
    if(pos>=i && pos<=mid) update(left,i,mid,pos,val);
    if(pos>=mid+1 && pos<=j) update(right,mid+1,j,pos,val);
    seg[curr]=seg[left]+seg[right];
    return;
}
int query(int curr,int l,int r,int i,int j)
{
    if(i>r || j<l) return 0;
    if(l>=i && r<=j) return seg[curr];
    int left= 2 * curr;
    int right= left+1;
    int mid= (l+r)/2;
    //cout<<l<<" || "<<r<<endl;
    return query(left,l,mid,i,j)+query(right,mid+1,r,i,j);
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;tt++)
    {
        memset(check,-1,sizeof(check));
        memset(agrindex,0,sizeof(agrindex));
        memset(seg,0,sizeof(seg));
        vec.clear();
        scanf("%d %d", &n, &q);
        for(int i=0;i<n;i++) scanf("%d", &arr[i]);
        for(int i=0;i<q;i++)
        {
            int l,r;
            scanf("%d %d", &l, &r);
            vec.push_back(node(r-1,l-1,i));
        }
        sort(vec.begin(),vec.end(),cmp);
        int ii=0;
        for(int i=0;i<n && ii<q;i++)
        {
            if(check[arr[i]]!=-1)
            {
                update(1,0,n-1,agrindex[arr[i]],0);

            }
            update(1,0,n-1,i,1);
            agrindex[arr[i]]=i;
            check[arr[i]]=1;
            while(vec[ii].r==i)
            {
                //cout<<vec[ii].l<<" || "<<vec[ii].r<<endl;
                ans[vec[ii].index]=query(1,0,n-1,vec[ii].l,vec[ii].r);
                //cout<<ans[vec[ii].index]<<" "<<i<<endl;
                ii++;
                if(ii>=q) break;
            }
        }
        printf("Case %d:\n",tt);
        for(int i=0;i<q;i++) cout<<ans[i]<<endl;
    }
    

}
