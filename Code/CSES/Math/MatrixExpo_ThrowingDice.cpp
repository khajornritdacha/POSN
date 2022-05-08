#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 2e6 + 10;
using ll = long long;

ll mod = 1e9+7;

vector<vector<ll>> mul(vector<vector<ll>> &A, vector<vector<ll>> &B){
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

vector<vector<ll>> expo(vector<vector<ll>> &base, ll pw){
    vector<vector<ll>> res(6, vector<ll>(6));
    for(int i = 0; i < 6; i++) res[i][i] = 1;
    while(pw){
        if(pw&1) res = mul(res, base);
        base = mul(base, base);
        pw /= 2;    
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;

    // vector<int> dp(6); dp[5]= 1; //let 5 be sum = 0

    // for(int i = 1; i <= n; i++){
    //     vector<int> ndp(6);
    //     ndp[5] = dp[0] + dp[1] + dp[2] + dp[3] + dp[4] + dp[5]; //let 5 be sum = i
    //     ndp[4] = dp[5];
    //     ndp[3] = dp[4];
    //     ndp[2] = dp[3];
    //     ndp[1] = dp[2];
    //     ndp[0] = dp[1];
    //     dp = ndp;
    // }
    // cout << dp[5] << "\n";

    vector<vector<ll>> base(6, vector<ll>(6));
    for(int i = 1; i <= 5; i++) base[i][i-1] = 1;
    for(int i = 0; i <= 5; i++) base[i][5] = 1;

    vector<vector<ll>> tot = expo(base, n);

    cout << tot[5][5] << "\n"; //form sum = 0 to sum = n

    return 0;
}