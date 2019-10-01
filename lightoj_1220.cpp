#include<bits/stdc++.h>
using namespace std;
int prime[1000006];
vector<int>vec;
void seive()
{
    for(int i=4;i<=100005;i+=2) prime[i]=1;
    for(int i=3;i*i<=100005;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=100005;j+= 2*i)
            prime[j]=1;
        }
    }

    for(int i=2;i<=100005;i++)
        if(prime[i]==0)
        vec.push_back(i);
}
int main()
{
    seive();
    int t;
    scanf("%d", &t);
    for(int k=1;k<=t;k++)
    {
        vector<int>fin;
        long long int n,temp;
        int num=0;
        scanf("%lld", &n);
         temp=n;
        if(n<0) n*=-1;
        for(int i=0;i<vec.size() && vec[i]*vec[i]<=n ;i++)
        {

            int res=0;

            if(n%vec[i]==0)
            {
                while(n%vec[i]==0)
                {

                    res++;
                    n/=vec[i];

                }
                fin.push_back(res);

            }
        }
        if(n>1) printf("Case %d: 1\n",k);
        else
        {


        for(int i=0;i<fin.size();i++)
        {

            num= __gcd(num,fin[i]);

        }

        if(temp<0)
        {
            while(num%2!=1)
            {
                num=num/2;
            }
        }
        printf("Case %d: %d\n",k,num);
        }

    }
}
