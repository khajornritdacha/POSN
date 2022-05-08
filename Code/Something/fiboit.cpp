#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
int fibo[N],n;

main(){
    ///iterative -> for
    ///recursive -> recursive func
    ///fibo(n) = fibo(n-1)+fibo(n-2); fibo(0)=fibo(1)=1
    cin >> n;
    fibo[0] = fibo[1] = 1;
    for(int i=2; i<=n; i++){
        fibo[i] = fibo[i-1]+fibo[i-2];
    }
    for(int i=1; i<=n; i++){
        cout << fibo[i] << " ";
    }
}
