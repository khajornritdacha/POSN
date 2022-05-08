#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

ll mod = 1e9+7;
ll fac[N],inv[N],to[N];

///https://atcoder.jp/contests/abc042/tasks/arc058_b

ll com(ll n, ll r){
    assert(n >= r);
    return ((fac[n]*inv[r])%mod * inv[n-r])%mod;
}

ll pw(ll a, ll p){
    if(p == 0) return 1;
    if(p == 1) return a;
    ll res = pw(a, p/2);
    res = (res*res)%mod;
    if(p&1) res = (res * a)%mod;
    return res;
}

int main(void){
    ll H,W,A,B; cin >> H >> W >> A >> B;
    
    fac[0] = inv[0] = 1;
    for(ll i = 1; i <= 2e5; i++){
        fac[i] = (fac[i-1]*i)%mod;
        inv[i] = pw(fac[i], mod-2);
    }

    ll ans = com(H-1+W-1, H-1);
    ll pre = 0;
    //cout << ans << "\n";
    for(ll i = 1; i <= B; i++){
        to[i] = (com(H-A+i-1, i-1)-pre+mod)%mod;
        pre = (pre+to[i])%mod;
        ans -= (to[i] * com(A-1+W-i, W-i))%mod;
        //cout << A-1 << " " << W-i << " " << com(A-1+W-i, W-i) << "\n";
        ans = (ans + mod)%mod;
    }

    // for(int i = 1; i <= B; i++){
    //     cout << to[i] << " \n"[i==B];
    // }

    cout << ans << "\n";
    return 0;
}