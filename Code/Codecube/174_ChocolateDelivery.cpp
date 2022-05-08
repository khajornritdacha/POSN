#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
const int N = 2e5+10;

int n,Q,x[1010],y[1010],idx[1010];
ll dp[1010],fa[N],inv[N],mod = 1e9+7;
//dp(i) = the number of ways to get at position i-th without passing any banned point
//dp(i) = the total number of ways from (1, 1) to (x[i], y[i]) minus sum of invalid ways( the number of ways to get from each banned point to current one)
//dp(i) = choose(x[i]-1 + y[i]-1, x[i]-1) - sum(dp[j] * choose(x[i]-x[j] + y[i]-y[j], x[i]-x[j])) ; x[j] <= x[i] and y[j] <= y[i]

ll pw(ll b, ll p){
    ll res = 1;
    while(p){
        if(p&1) res = (res*b)%mod;
        b = (b*b)%mod;
        p /= 2;
    }
    return res;
}

ll choose(int n, int r){
    return (fa[n] * inv[r] %mod *inv[n-r] %mod);
}

ll cal(int ex, int ey){
    ll res = choose(ex+ey-2, ex-1), tmp = 0;
    
    for(int i = 1; i <= n; i++){
        if(x[idx[i]] <= ex and y[idx[i]] <= ey){
            tmp += (dp[idx[i]] * choose(ex-x[idx[i]]+ey-y[idx[i]], ex-x[idx[i]]))%mod;
            tmp %= mod;
        }
    }

    return (res-tmp+mod)%mod;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        idx[i] = i;
    }

    sort(idx+1, idx+n+1, [&](const int &i, const int &j){
        if(x[i] != x[j]) return x[i] < x[j];
        return y[i] < y[j];
    });

    fa[0] = inv[0] = 1;
    for(int i = 1; i < N; i++){
        fa[i] = (fa[i-1] * i)%mod; //precalculate factorial of 1...2e5
    }
    inv[N-1] = pw(fa[N-1], mod-2);

    for(int i = N-2; i >= 1; i--){
        inv[i] = (inv[i+1] * (i+1))%mod;
    }

    for(int i = 1; i <= n; i++){
        dp[idx[i]] = cal(x[idx[i]], y[idx[i]]);
    }

    //for(int i = 1; i <= n; i++) cout << dp[i] << " \n"[i==n];

    while(Q--){
        int ex, ey; cin >> ex >> ey;
        cout << cal(ex, ey) << "\n";
    }
    return 0;
}