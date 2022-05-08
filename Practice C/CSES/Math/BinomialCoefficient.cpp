#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 2e6 + 10;
using ll = long long;

//https://cses.fi/problemset/task/1079/

ll fa[N], mod = 1e9+7;

ll pw(ll b, ll p){
    ll res = 1;
    while(p){
        if(p&1) res = (res * b)%mod;
        b = (b*b)%mod;
        p /= 2;
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    fa[0] = 1;
    for(int i = 1; i < N; i++) fa[i] = (fa[i-1] * i)%mod;

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << (fa[a] * pw(fa[b], mod-2)%mod * pw(fa[a-b], mod-2)%mod) << "\n";
    }

    return 0;
}