#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int n,f[N],mod=10001;
main(){
    ///Catalan Number
    cin >> n;
    f[0] = f[1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            f[i] += (f[j]*f[i-j-1])%mod;
            f[i] %= mod;
        }
    }
    cout << f[n];
}
