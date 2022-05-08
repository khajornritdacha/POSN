#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 25;
using ll = long long;
const ll INF = 2e18;

//just like TOI16 dino cell

ll n,K,a[N];

ll solve(int lv = 1, int si = -1, ll lc = 1){
    if(lv == K+1){
        if(lc == 1) return 0;
        return n/lc*si;
    }
    ll res = solve(lv+1, si, lc);
    ll tmp;
    if(lc >= INF/a[lv]){ //in case that lc * a[lv] overflows then dividing n by INF will always result in 0
        tmp = INF;
    } else {
        tmp = lc*a[lv];
    }
    res += solve(lv+1, si*-1, tmp);
    return res;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= K; i++){
        cin >> a[i];
    }

    cout << solve() << "\n";
    return 0;
}