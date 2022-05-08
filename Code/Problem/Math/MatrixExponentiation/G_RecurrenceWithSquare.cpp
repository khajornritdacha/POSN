#include <bits/stdc++.h>
using namespace std;


using ll = long long;
ll mod = 1e9+7;

vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> res(A.size(), vector<ll>(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B[0].size(); j++){
            for(int k = 0; k < B.size(); k++){
                res[i][j] += A[i][k]*B[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> expo(vector<vector<ll>> base, ll pw){
    vector<vector<ll>> res(base.size(), vector<ll>(base.size()));
    for(int i = 0; i < res.size(); i++) res[i][i] = 1;
    while(pw){
        if(pw&1){
            res = mul(res, base);
        }
        base = mul(base, base);
        pw /= 2;
    }
    return res;
}

int main(void){
    int n, a[20], c[20];
    ll K,P,Q,R;
    cin >> n >> K;
    vector<vector<ll>> dp(1, vector<ll>(n+6));
    vector<vector<ll>> base(n+6, vector<ll>(n+6));
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    cin >> P >> Q >> R;

    if(K < n){
        cout << a[K] << "\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        dp[0][i] = a[i];
    }
    dp[0][n] = P, dp[0][n+1] = Q, dp[0][n+2] = R, dp[0][n+3] = (Q*n)%mod, dp[0][n+4] = (R*n)%mod, dp[0][n+5] = (R*n*n)%mod;
    base[n][n] = 1;
    base[n+1][n+1] = 1;
    base[n+2][n+2] = 1;
    base[n+3][n+3] = 1; base[n+1][n+3] = 1;
    base[n+4][n+4] = 1; base[n+2][n+4] = 1;
    base[n+5][n+5] = 1; base[n+4][n+5] = 2; base[n+2][n+5] = 1;
    base[n][n-1] = 1, base[n+3][n-1] = 1, base[n+5][n-1] = 1;
    for(int i = 0; i < n; i++){
        base[i][n-1] = c[n-i];
    }
    for(int i = 0; i < n-1; i++){
        base[i+1][i] = 1;
    }

    vector<vector<ll>> res = expo(base, K-n+1);
    dp = mul(dp, res);
    cout << dp[0][n-1] << "\n";
    return 0;
}
