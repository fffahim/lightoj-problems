#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        long long int s;
        scanf("%lld", &s);
        long long int a=ceil(sqrt(s));
        long long int n=(a-1)*(a-1);
        long long int m=a*a;
        if(a%2!=0)
        {
            if((s-n)>=a)
                printf("Case %d: %lld %lld\n",i,1+m-s,a);
            else
                printf("Case %d: %lld %lld\n",i,a,s-n);

        }
        else
        {
             if((s-n)>=a)
                printf("Case %d: %lld %lld\n",i,a,1+m-s);
             else
                printf("Case %d: %lld %lld\n",i,s-n,a);


        }
    }
}
