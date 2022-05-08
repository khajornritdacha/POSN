#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
int f[N];

int fibo(int n){
    if(n == 0 or n == 1)
        return 1;
    if(f[n] != 0)
        return f[n];
    return f[n] = fibo(n-1)+fibo(n-2);
}///recursive

main(){
    ///iterative -> for
    ///recursive -> recursive func
    ///fibo(n) = fibo(n-1)+fibo(n-2); fibo(0)=fibo(1)=1
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cout << fibo(i) << " ";
    }
}
