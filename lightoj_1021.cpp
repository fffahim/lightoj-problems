#include<bits/stdc++.h>
using namespace std;
long long int dp[(1<<16)+2][20];
int arr[16];
int n,base,k;
int sett(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
long long int bitmask(int maskm,int rem)
{
    if(maskm==(1<<n)-1) 
        if(rem==0) return 1;
        else return 0;
    if(dp[maskm][rem]!=-1) return dp[maskm][rem];
    long long int maxx=0;
    for(int i=0;i<n;i++)
    {
        if(check(maskm,i)==0)
        {
            int temp = rem*base + arr[i];
            maxx+= bitmask(sett(maskm,i),temp%k);

        }
    }
    return dp[maskm][rem]=maxx;

}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {   
        memset(dp,-1,sizeof(dp));
        char str[16];
        scanf("%d %d", &base, &k);
        scanf("%s", str);
        n=strlen(str);
         for(int j=0; j<n; j++)
        {
            if(str[j]>='0' and str[j]<='9') arr[j] = str[j] - '0';
            else arr[j] = str[j] - 'A' + 10;
        }
        cout<<"Case "<<i<<": "<<bitmask(0,0)<<endl;


    }

}