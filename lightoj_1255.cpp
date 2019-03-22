/*
1255 - Substring Frequency
*/
#include<bits/stdc++.h>
using namespace std;
char text[1000005];
char pat[1000005];
int pi[1000000];
int l,p;
int prefix()
{
    int now;
    pi[0]=now=-1;
    for(int i=1;i<p;i++)
    {
        while(now!=-1 && pat[now+1]!=pat[i])
            now=pi[now];
        if(pat[now+1]==pat[i]) pi[i]=++now;
        else pi[i]=now=-1;
    }

}
int kmp()
{   int sum=0;
    int now=-1;
    for(int i=0;i<l;i++)
    {
        while(now!=-1 && pat[now+1]!= text[i])
            now=pi[now];
        if(pat[now+1]==text[i])
        {
            ++now;

            }
        else now=-1;
        if(now+1==p)
            {
                sum++;
                now=pi[now];

            }
    }
    return sum;
}
int main()
{
    int t,i=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s",text);
        scanf("%s",pat);
        l=strlen(text);
        p=strlen(pat);
        prefix();
        printf("Case %d: %d\n",++i,kmp());
    }
}

