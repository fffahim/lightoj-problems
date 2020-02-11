#include<bits/stdc++.h>
using namespace std;
int health[20],powers[20][20],n;
int dp[(1<<16)+2][20];
int Set(int N,int pos){return N=N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int func(int i,int mask)
{
    if(i>=n) return 0;
    if(dp[mask][i]!=-1) return dp[mask][i];
    int fin = 1e9 +2;
    for(int x = 1;x<=n;x++)
    {
        if(!check(mask,x))
        {
            for(int j=0;j<=n;j++)
            {
                if(check(mask,j))
                {   
                    int sum=0;
                    if(powers[j][x-1]==0) sum+=(1e9 +2) ; 
                    else 
                    {
                        sum+=health[x-1]/powers[j][x-1] + func(i+1, Set(mask,x));
                        if(health[x-1]%powers[j][x-1] !=0) sum++;
                        
                    }
                    fin = min(fin,sum);
                }
            }
        }
    }
    return dp[mask][i]=fin;
}
int main()
{
    //freopen("fahimin.txt","r",stdin);
    //freopen("fahimout.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {   
        int mask =0;
        memset(health,0,sizeof(health));
        memset(powers,0,sizeof(powers));
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int j=0;j<n;j++) cin>>health[j];
        for(int j=0;j<n;j++) powers[0][j]= 1;
        for(int j=1;j<=n;j++)
        {
           char str[n+1];
           cin>>str;
           for(int k=0;k<n;k++)
           {
               powers[j][k]=str[k]-'0';
           }
        }
    int res = 1e9 + 2;
    mask=Set(mask,0);
    for(int j=0;j<n;j++)
    {
      int sum=0;
      sum+=health[j]/powers[0][j] + func(1,Set(mask,j+1));
      res = min(res,sum); 
    }
        cout<<"Case "<<i<<": "<<res<<endl;
    }    
}