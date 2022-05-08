#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f[500000];
int fibo(int n){
    if(n<2)
        return n;
    int f0=0,f1=1,f2;
    for(int i=2;i<=n;i++){
        f2 = f1+f0;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}
main(){
    cin >> n;
    cout << fibo(n);
}
