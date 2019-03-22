#include<bits/stdc++.h>
using namespace std;
long long int arr[10005];
long long int a, b, c, d, e, f;
long long int fn( long long int n ) {
    if(n<0) return 0;
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(arr[n]!=-1) return arr[n];
    arr[n]=fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ;
    arr[n]=arr[n]%10000007;
    return arr[n];
}
int main() {
    long long int n;
    int caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
            memset(arr,-1,sizeof(arr));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
