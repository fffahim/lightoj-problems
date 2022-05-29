#include<bits/stdc++.h>
using namespace std;
char str1[100],str2[100];
int len1,len2,dp[100][100],fin;
long long int dp2[100][100][100];

int lcs(int i,int j)
{
    if(i>=len1 || j>=len2) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(str1[i]==str2[j])
    {
        ans=1+lcs(i+1,j+1);
    }
    else
    {
        int pro1= lcs(i+1,j);
        int pro2= lcs(i,j+1);
        ans=max(pro1,pro2);
    }
    return dp[i][j]=ans;
}

long long int func(int i,int j,int countn)
{
    if(i>=len1 || j>=len2)
    {
        int temp1= len1-i;
        int temp2= len2-j;
        if(temp1+temp2+countn==fin)
        {
             return 1;
        }
        else return 0;
    }
    if(dp2[i][j][countn]!=-1) return dp2[i][j][countn];
    long long int ans=0;
    if(str1[i]==str2[j])
    {
        ans=func(i+1,j+1,countn+1);
    }
    else
    {
        long long int pro1= func(i+1,j,countn+1);
        long long int pro2= func(i,j+1,countn+1);
        ans=pro1+pro2;
    }
    return dp2[i][j][countn]=ans;
}

int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        cin>>str1>>str2;
        len1= strlen(str1);
        len2= strlen(str2);
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++) dp[i][j]=-1;
        }
        memset(dp2,-1,sizeof(dp2));
        fin=len1+len2-lcs(0,0);
        cout<<"Case "<<tt<<": "<<fin<<" "<<func(0,0,0)<<endl;
    }

}
