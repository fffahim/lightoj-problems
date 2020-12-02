#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[100005];
int func(int mid)
{
    int total=0;
    int cap=m;
    for(int i=0;i<n && cap>0;i++)
    {
        if(total+arr[i]<=mid) total+=arr[i];
        else
        {
            cap--;
            if(arr[i]<=mid) total=arr[i];
            else return -1;
        }
        
    }
    if(cap>0) return 1;
    else return -1;
}
int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m;
        int maxx=0,sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            maxx=max(maxx,arr[i]);
            sum+=arr[i];
        }
        int left=maxx,right=sum;
        int fin=sum;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int ans=func(mid);
            if(ans==1) 
            {
                fin=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        cout<<"Case "<<k<<": "<<fin<<endl;
    }
}