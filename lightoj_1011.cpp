#include<bits/stdc++.h>
using namespace std;
int arr[20][20],dp[20][1<<15+5];
int n;
int sett(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int bitmask(int maskm,int men)
{
    if(men>n) return 0;
    if(dp[men][maskm]!=-1) return dp[men][maskm];
    int maxx=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(check(maskm,i)==0)
        {
            maxx=arr[men][i]+ bitmask(sett(maskm,i),men+1);
             ans=max(ans,maxx);

        }
    }
    return dp[men][maskm]=ans;

}
int main()
{
    int t;
    scanf("%d", &t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d", &n);
        memset(arr,0,sizeof(arr));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            scanf("%d", &arr[i][j]);
        }
        cout<<"Case "<<k<<": "<<bitmask(0,0)<<endl;


    }
}
