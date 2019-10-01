#include<bits/stdc++.h>
using namespace std;
int n = 5000002;
unsigned long long int phi[5000005];
int main()
{
    for(int i=2;i<=n;i++) phi[i]=i;
    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=n;j+=i)
            {
                phi[j]=(phi[j]/ i )* (i-1);
            }
        }
    }
    for(int i=3;i<=5000005;i++)
    {
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }


    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        int a,b;
        unsigned long long int sum=0;
        scanf("%d %d", &a, &b);
        sum= phi[b]-phi[a-1];
        cout<<"Case "<<i<<": "<<sum<<"\n";
    }

}
