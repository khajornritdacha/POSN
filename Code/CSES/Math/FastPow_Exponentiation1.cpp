#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 1e9+7;

ll pw(ll a, ll p){
    ll res = 1;
    while(p){
        if(p&1) res = (res*a)%mod;
        a = (a*a)%mod;
        p >>= 1;
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll a,b; cin >> a >> b;
        cout << pw(a, b) << "\n";
    }
    return 0;
}