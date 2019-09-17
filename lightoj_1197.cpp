#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("iinput.txt","r",stdin);
    //freopen("ooutput.txt", "w",stdout);
    int t;
    scanf("%d", &t);
    for(int z=1;z<=t;z++)
    {
        long long int a,b;
        scanf("%lld %lld", &a, &b);
        if(a==1) a++;
        int x= sqrt(b);
        int arr[x+5],arr1[b-a+1];
        memset(arr,-1,sizeof(arr));
        arr[0]=arr[1]=0;
        for(int i=4;i<=x;i+=2) arr[i]=0;
        for(int i=3;i<=sqrt(x);i+=2)
        {
            for(int j=i*i;j<=x;j+=i)
            arr[j]=0;

        }

        vector<int>vec;
        for(int i=1;i<=x;i++) if(arr[i]==-1) vec.push_back(i);
        memset(arr1,0,sizeof(arr1));
        for(int i=0;i<vec.size() && vec[i]<=x;i++)
        {

            int p= vec[i];
            long long int j=p*p;
            if(j<a) j=((a+p-1)/p)*p;

            for( ;j<=b; j+=p)
            {

                arr1[j-a]=1;

            }
        }
        int sum=0;
        for(long long int i=a;i<=b;i++)
        {
            if(arr1[i-a]==0) sum++;
        }
        cout<<"Case "<<z<<": "<<sum<<"\n";
    }
}
