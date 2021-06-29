#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
pair<int,int>seg[3*100005];
void build(int curr, int l, int r)
{
   if(l==r)
   {
      seg[curr].first=arr[l];
      seg[curr].second=arr[l];
      return;
   }
   int left = curr*2;
   int right = left+1;
   int mid = (l+r)/2;
   build(left,l,mid);
   build(right,mid+1,r);
   seg[curr].first = max(seg[left].first,seg[right].first);
   seg[curr].second = min(seg[left].second,seg[right].second);
   return;

}
pair<int,int> query(int curr, int i, int j, int l, int r)
{
   if(i>r || j<l) return {0,1e8+5};
   if(i>=l && j<=r)
   {
      return seg[curr];
   } 
   int left = curr*2;
   int right = left+1;
   int mid = (i+j)/2;
   pair<int,int>temp,fin;
   temp = query(left,i,mid,l,r);
   fin.first = temp.first;
   fin.second = temp.second;
   temp= query(right,mid+1,j,l,r);
   fin.first = max(fin.first,temp.first);
   fin.second = min(fin.second,temp.second);
   return fin;
}
int main()
{
   int t;
   cin>>t;
   for(int tt=1;tt<=t;tt++)
   {
      int n,d;
      scanf("%d %d", &n, &d);
      for(int i=0;i<n;i++) scanf("%d", &arr[i]);
      build(1,0,n-1);
      int maxx=0;
      for(int i=0;i<=n-d;i++)
      {
         pair<int,int> p = query(1,0,n-1,i,i+d-1);
         maxx=max(maxx,p.first-p.second);
      }
      printf("Case %d: %d\n",tt,maxx);
      
   }

}
