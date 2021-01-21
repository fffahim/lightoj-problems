#include<bits/stdc++.h>
using namespace std;
int main()
{
    float arr[5],fin;
    for(int i=0;i<4;i++) cin>>arr[i];
    cin>>fin;
    sort(arr,arr+4);
    float sum=0;
    float temp= (arr[1]+arr[2]+arr[3])/3.00;
    float temp2=(arr[0]+arr[1]+arr[2])/3.00;
    temp = floorf(temp * 100) / 100; 
    temp2= floorf(temp2 * 100) / 100; 
    if(temp<=fin)
    {
        cout<<"infinite\n";
        return 0;
    }
    else if(temp2>fin) 
    {
        cout<<"impossible\n";
        return 0;
    }
    float index= -1;
    float check= arr[1]+arr[2];
    float first= arr[0];
    float last= arr[3];
    int i=32;
    while(i--)
    {
        float mid= (last+first)/2.00;
        temp=(check+mid)/3.00;
        if(fin-temp>=0.001)
        {
            cout<<temp<<" "<<fin<<endl;
            index=mid;
            first= mid;
        }
        else if(fin-temp<0.001)
        {
            last=mid;
        }
    }
    cout<<index<<endl;
}