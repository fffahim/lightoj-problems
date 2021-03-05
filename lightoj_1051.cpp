#include<bits/stdc++.h>
using namespace std;
char str[100];
int dp[55][55][55],dp2[55][55][55],len,check;
map<char,int>m;
int func(int i,int vowl,int cons)
{
    if(i>=len) return 0;
    if(dp[i][vowl][cons]!=-1) return dp[i][vowl][cons];
    int ans=0;
    if(str[i]=='?')
    {
        check=1;
        if(vowl+1>=3) ans=max(ans,1+func(i+1,vowl+1,0));
        else ans=max(ans,func(i+1,vowl+1,0));
        if(cons+1>=5) ans=max(ans,1+func(i+1,0,cons+1));
        else ans=max(ans,func(i+1,0,cons+1));
    }
    else if(m[str[i]]==1)
    {
        if(vowl>0)
        {
            if(vowl+1>=3) ans=max(ans,1+func(i+1,vowl+1,cons));
            else ans=max(ans,func(i+1,vowl+1,cons));
        }
        else ans=max(ans,func(i+1,vowl+1,0));
    }
    else
    {
        if(cons>0)
        {
            if(cons+1>=5) ans=max(ans,1+func(i+1,vowl,cons+1));
            else ans=max(ans,func(i+1,vowl,cons+1));
        }
        else ans=max(ans,func(i+1,0,cons+1));
    }
    return dp[i][vowl][cons]=ans;
}
int func2(int i,int vowl,int cons)
{
    if(vowl>=3 || cons>=5) return 1;
    if(i==len)
    {
        if(vowl<3 && cons<5)
        {
            return 2;
        }
        else return 1;
    }
    if(dp2[i][vowl][cons]!=-1) return dp2[i][vowl][cons];
    int ans=0;
    if(str[i]=='?')
    {
        check=1;
        ans=max(ans,func2(i+1,vowl+1,0));
        ans=max(ans,func2(i+1,0,cons+1));
    }
    else if(m[str[i]]==1) ans=max(ans,func2(i+1,vowl+1,0));
    else ans=max(ans,func2(i+1,0,cons+1));
    return dp2[i][vowl][cons]=ans;
}
int main()
{
    int t;
    cin>>t;
    m['A']=1;
    m['E']=1;
    m['I']=1;
    m['O']=1;
    m['U']=1;
    for(int tt=1;tt<=t;tt++)
    {
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        check=0;
        cin>>str;
        len=strlen(str);
        int ans1= func(0,0,0);
        int ans2= func2(0,0,0);
        cout<<"Case "<<tt<<": ";
        if(check==0)
        {
            if(ans1==0) cout<<"GOOD\n";
            else cout<<"BAD\n";
        }
        else
        {
            if(ans1>0)
            {
                if(ans2==2) cout<<"MIXED\n";
                else cout<<"BAD\n";

            }
            else cout<<"GOOD\n";
        }
    }
}
