#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 3010;
using ll = long long;

int dp[310][N],a[N],n,K,qs[N];

void solve(int k, int l = 1, int r = n, int optl = 1, int optr = n){
    if(l > r) return;

    int mid = (l+r)/2, mn = 1e9, pos = -1;
    for(int i = optl, ed = min(mid, optr); i<=ed; i++){
        int tmp = max(dp[k-1][i-1], qs[mid]-qs[i-1]);
        if(tmp < mn){
            mn = tmp;
            pos = i;
        }
    }

    dp[k][mid] = mn;
    solve(k, l, mid-1, optl, pos);
    solve(k, mid+1, r, pos, optr);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
        dp[1][i] = qs[i];
    }
    for(int i=2; i<=K; i++)
        solve(i);
    cout << dp[K][n];
}
