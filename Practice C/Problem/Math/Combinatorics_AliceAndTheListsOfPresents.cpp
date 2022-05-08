#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 1e9+7;

///https://codeforces.com/problemset/problem/1236/B

ll pw(ll a, ll p){
    ll res = 1;
    while(p){
        if(p&1)
            res = (res*a)%mod;
        a = (a*a)%mod;
        p /= 2;
    }
    return res;
}

int main(void){
    ll n,m;
    cin >> n >> m;
    cout << pw( (pw(2ll, m)-1 + mod)%mod, n) << "\n"; ///(2^m-1)^n

    return 0;
}