/*
  making huge palindromes
  algorithm: kmp
*/
#include<bits/stdc++.h>
using namespace std;
char text[1000005];
char pat[1000005];
int pi[1000005];
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

    }

    return now;

}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",text);
        p=l=strlen(text);
        reverse_copy(text,text+l,pat);

        prefix();
        printf("Case %d: %d\n",i, 2*l-(kmp()+1));
    }
}
