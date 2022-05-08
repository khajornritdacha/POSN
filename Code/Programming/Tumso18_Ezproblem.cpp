#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;
using ll = long long;

ll n,A,mod=1e9+7;

///f(n, a) = (2a)^(n-1) + (2a)^(n) + ... + (2a)^(2n-2) -> geometric series
///from sum of geometric series formula Sn = a1*(r^n-1)/(r-1)
///        = (2a)*( (2a)^n -1 ) / (2a-1)

ll pw(ll b, ll p){
    ll tmp = 1,now = b, cnt = p;
    while(p){
        if(p&1){
            tmp = (tmp*now)%mod;
        }
        now = (now*now)%mod;
        p/=2;
    }
    //cout << "POW : " << cnt << " = " << tmp << "\n";
    return tmp;
}



void test_case(){
    cin >> n >> A;
    if(n == 0){ cout << "0\n"; return; }
    ll res1 = (pw(2*A, 2*n-1)-pw(2*A, n-1)+mod)%mod;
    res1 = (res1*pw(2*A-1, mod-2))%mod; ///divide (inverse mod)
    cout << res1 << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
