#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 2e6 + 10;
using ll = long long;

//https://cses.fi/problemset/task/1716/
//https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)
//star and bar
//consider there are m star(the number of apples) and n-1 bar(the number of stdents - 1)
//there are (m+n-1) places to place (n-1) bar

ll fa[N],n,m,mod = 1e9+7;

ll pw(ll b, ll p){
    ll res = 1;
    while(p){
        if(p&1) res = (res*b)%mod;
        b = (b*b)%mod;
        p /= 2;
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    fa[0] = 1;
    for(int i = 1; i < N; i++){
        fa[i] = (fa[i-1]*i)%mod;
    }

    cout << (fa[m+n-1]*pw(fa[n-1], mod-2)%mod *pw(fa[m], mod-2)%mod) << "\n";

    return 0;
}