#include<bits/stdc++.h>
using namespace std;
long long x,val,n,mod=2553;
main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        val = (val+((n-i)*(n-i+1)/2*x)%mod)%mod;
    }
    cout << val;
}
