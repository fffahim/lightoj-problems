#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
pair<ll,ll>seg[400005];
void update(int curr,int i,int j,int l,int r,int val)
{
    if(j<l || i>r) return;
    if(i>=l && j<=r)
    {
        seg[curr].first +=val;
        seg[curr].second+=((j-i+1)*val);
        return;
    }
    int left = curr*2;
    int right = left+1;
    int mid = (i+j)/2;
    update(left,i,mid,l,r,val);
    update(right,mid+1,j,l,r,val);
    seg[curr].second = seg[left].second + seg[right].second + (j-i+1)*seg[curr].first;
    return;
}
ll res(int curr,int i,int j,int l, int r,ll prop)
{
    // cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
    if(j<l || i>r) return 0;
    if(i>=l && j<=r)
    {
       return seg[curr].second+(prop * (j-i+1));
    }
    int left = curr*2;
    int right = left+1;
    int mid = (i+j)/2;
    ll p1 = res(left, i, mid, l, r, prop + seg[curr].first); 
    ll p2 = res(right,mid+1, j, l, r, prop + seg[curr].first);
    return p1+p2; 
}
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n,q;
        cin>>n>>q;
        memset(seg,0,sizeof(seg));
        printf("Case %d:\n",tt);
        for(int i=0;i<q;i++)
        {
            int temp,x,y,val;
            cin>>temp;
            if(temp==0)
            {
                cin>>x>>y>>val;
                update(1,0,n-1,x,y,val);
            }
            else
            {
                cin>>x>>y;
                cout<<res(1,0,n-1,x,y,0)<<endl;
            }
        }

    }
}