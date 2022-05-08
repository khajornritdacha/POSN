#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 3010;
using ll = long long;

int n,a[N],K;
ll dp[N][N],qs[N];

///https://cses.fi/problemset/task/2086
///Divide and Conquer DP

void solve(int l, int r, int optl, int optr, int k){
    if(l > r) return;
    int mid = (l+r)/2;

    ///solve for dp(k, mid)
    ll mn = 1e18, pos = -1;
    for(int i=optl, ed=min(mid, optr); i<=ed; i++){ ///Ascertained optimal answer will be in range [optl, min(mid, optr)]
        ll tmp = dp[k-1][i-1] + (qs[mid]-qs[i-1])*(qs[mid]-qs[i-1]);
        if(tmp < mn){
            mn = tmp;
            pos = i;
        }
    }

    dp[k][mid] = mn;
    solve(l, mid-1, optl, pos, k);
    solve(mid+1, r, pos, optr, k);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
        dp[1][i] = qs[i]*qs[i];
    }
    for(int i=2; i<=K; i++){
        solve(1, n, 1, n, i);
    }
    cout << dp[K][n];
}
