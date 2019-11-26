#include<bits/stdc++.h>
using namespace std;
int dp[10005][105],n,arr[100005];
int greedy(int i,int k,int w)
{
    if(i>=n || k<=0) return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    int j=i+1,sum=1;
    while(abs(arr[j]-arr[i])<=w && j<n)
    {
        sum++;
        j++;
    }
    int prof1=sum+greedy(j,k-1,w);
    int prof2=greedy(i+1,k,w);
    return dp[i][k]=max(prof1,prof2);
}
int main()
{
    // freopen("lightin.txt", "r", stdin);
    // freopen("lightout.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        int w,k;
        memset(dp,-1,sizeof(dp));
        scanf("%d %d %d", &n, &w, &k);
        int temp;
        for(int j=0;j<n;j++)
        {
            scanf("%d %d",&temp, &arr[j]);
        }
        sort(arr,arr+n);
        cout<<"Case "<<i<<": "<<greedy(0,k,w)<<endl;


    }
}