#include<bits/stdc++.h>
using namespace std;
int n,check;
int func(int u,int r,int d,int l,char curr)
{
    int ans=0;
    if(curr=='r')
    {
        if(r<0 || r==n) return 0;
        if(r<n-1) ans^=func(u,0,d,l,'d');
        if(r>0) ans^=func(u,0,d-1,l,'d');
    }
    else if(curr=='d')
    {
        if(d<0 || d==n) return 0;
        if(d<n-1) ans^=func(u,r,0,l,'l');
        if(d>0) ans^=func(u,r,0,l-1,'l');
    }
    else
    {
        if(l<0 || l>n-2) return 0;
        else
        {
            check=1;
            return 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int u,r,d,l;
       cin>>n>>u>>r>>d>>l;
       int ans=0;
       check=0;
       if(u==n) ans^= func(0,r-1,d,l-1,'r');
       else if(u<=n-2) ans^=func(0,r,d,l,'r');
       if(u!=n && u>0)
       {
           ans^=func(0,r-1,d,l,'r');
           ans^=func(0,r,d,l-1,'r');
       }
       if(check==1) cout<<"YES\n";
       else cout<<"NO\n";
    }
}
