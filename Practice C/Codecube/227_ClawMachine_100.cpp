#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10, K = 100, mod = 1e9+7;
using ll = long long;

//https://beta.programming.in.th/tasks/codecube_227

int n,Q,a[N];
ll dp[N][K+5], F[K+5];

void add(ll &A, ll B){
    A += B;
    if(A >= mod) A -= mod;
}

void sub(ll &A, ll B){
    A -= B;
    if(A < 0) A += mod;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dp[0][0] = 1; //define dp(i, k) as the number of ways to make sum equal to k with elements in prefix 1..i (Knapsack)
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        for(int k = 1; k <= K; k++){
            dp[i][k] = dp[i-1][k];
            if(k - a[i] >= 0) 
                add(dp[i][k], dp[i-1][k-a[i]]);
        }
    }

    while(Q--){
        int l, r, W; cin >> l >> r >> W;
        F[0] = 1; //define F(i) as the number of ways to select elements that total weight is i in range l to r
        for(int i = 1; i <= W; i++){
            F[i] = dp[r][i]; //F(i) = the number of ways from 1..r subtract with those that are overlap 
            for(int j = 0; j < i; j++){
                sub(F[i], (F[j] * dp[l-1][i-j])%mod);
            }
        }
        cout << F[W] << "\n";
    }
    return 0;
}