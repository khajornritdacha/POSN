#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 510;

///since a^(p-1) = 1
///a^b^c / a^(p-1) = a^(b^c - n(p-1)) = a^(b^c mod (p-1)) mod p

ll pw(ll a, ll p, ll mod){
    if(p == 0) return 1;
    if(p == 1) return a;
    ll res = pw(a, p/2, mod);
    res = (res*res)%mod;
    if(p&1) res = (res*a)%mod;
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        ll mod = 1e9+7;
        ll a, b, c; cin >> a >>  b >> c;
        b = pw(b, c, mod-1);
        a = pw(a, b, mod);
        cout << a << "\n";
    }
    return 0;
}
