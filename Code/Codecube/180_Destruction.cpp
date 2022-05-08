#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using ll = long long;
const int maxn = 5e4+10;
int N,K,M;
vector<ll> qs;
ll dp[maxn][2],mn[maxn][2];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> M;
    qs.resize(N+1,0);
    memset(dp, 127, sizeof(dp));
    memset(mn, 127, sizeof(mn));
    dp[0][0] = 0;
    mn[0][0] = 0;
    for(int i=1; i<=N; i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }
    for(int i=1; i<=N; i++){
        mn[i][0] = min(mn[i-1][0], -qs[i-1]);
    }
    for(int k=1; k<=K; k++){
        for(int i=1; i<=N; i++){
            dp[i][k%2] = 1e18;
            mn[i][k%2] = 1e18;
        }
        for(int i=(k*M)+k-1; i<=N; i++){
            dp[i][k%2] = min(mn[i-M+1][(k-1)%2]+qs[i], dp[i-1][k%2]);
            mn[i][k%2] = min(mn[i-1][k%2], dp[i-2][k%2]-qs[i-1]);
        }
    }
    cout << qs[N]-dp[N][K%2] << "\n";
}

///define dp(i, k) = min(dp(j-2, k-1) + qs[i] -qs[j-1]); i-j+1>=M
///rearrange and define mn(i, k) = dp(j-2, k-1) - qs[j-1]; j<=i
///observe and redefine mn(i, k) = min(dp(i-2, k)-qs[i-1], mn(i-1, k));
