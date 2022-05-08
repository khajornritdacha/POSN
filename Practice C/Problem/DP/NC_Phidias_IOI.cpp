#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 610;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int W,H,n,w[N],h[N],dp[N][N];
bool vi[N][N];
///https://dmoj.ca/problem/ioi04p4
int solve(int i, int j){
    if(vi[i][j])
        return dp[i][j];
    vi[i][j] = true;
    dp[i][j] = i*j;
    for(int k=1; k<=n; k++){
        if(i-h[k] >= 0 and j-w[k] >= 0)
            dp[i][j] = min({dp[i][j], solve(h[k], j-w[k])+solve(i-h[k], j), solve(i-h[k], w[k])+solve(i, j-w[k])});
    }
    return dp[i][j];
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); //freopen("teamwork.in", "r", stdin); freopen("teamwork.out", "w", stdout);
    cin >> W >> H >> n;
    for(int i=1; i<=n; i++){
        cin >> w[i] >> h[i];
    }
    cout << solve(H, W);
}
