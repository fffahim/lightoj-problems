#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x=1000;
    scanf("%d", &t);
    int arr[x+1];
        memset(arr,0,sizeof(arr));
        arr[0]=arr[1]=1;
        for(int i=4;i<=x;i+=2) arr[i]=1;
        for(int i=3;i<=sqrt(x);i+=2)
        {
            for(int j=i*i;j<=x;j+=i)
                arr[j]=1;
        }

    while(t--)
    {
        int n,maxx=0,temp;
        scanf("%d", &n);
        int p = sqrt(n);
        vector<int>vec;
         for(int i=1;i<=p;i++)
        {
            if(arr[i]==0) vec.push_back(i);
        }

        for(int i=0;i<vec.size() && vec[i]<=p;i++)
        {
             temp=0;

            if(n%vec[i]==0)
            {
                while(n%vec[i]==0)
                {
                    n/=vec[i];
                    temp++;
                }
            }
            maxx=max(maxx,temp);
        }
        if(maxx==0) maxx=1;
        cout<<maxx<<"\n";


    }
}
