//Source : USACO December 2021 GOLD (Paired Up)
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1161
//Sol : http://www.usaco.org/current/data/sol_prob1_gold_dec21.html

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9+10;

int solvemin(vector<pair<int, int>> &vec, int K){
    if(!(vec.size()&1)) return 0;
    int res = INF;
    for(int i = 0; i < vec.size(); i++){
        if(!(i&1) or vec[i+1].first - vec[i-1].first <= K) res = min(res, vec[i].second);
    }
    return res;
}

int solvemax(vector<pair<int, int>> &vec, int K){
    int n = vec.size();
    vector<pair<int, int>> dp(n+1);
    dp[n] = {0, -INF}; //.first for even size, .second for odd size

    // for(auto [x, y] : vec) cout << x << " " << y
    for(int i = n-1; i >= 0; i--){
        dp[i] = dp[i+1];
        int ub = upper_bound(vec.begin(), vec.end(), make_pair(vec[i].first+K, INF))-vec.begin();

        if(i == 0 or i == n-1 or vec[i+1].first-vec[i-1].first <= K or !(n-i&1)) //even
            dp[i].first = max(dp[i].first, dp[ub].second + vec[i].second);
        if(i == 0 or i == n-1 or vec[i+1].first-vec[i-1].first <= K or (n-i&1)) //odd
            dp[i].second = max(dp[i].second, dp[ub].first + vec[i].second);
    }

    return (n&1) ? dp[0].second : dp[0].first;
}



int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int T, n, K; cin >> T >> n >> K;
    int x[n+5], y[n+5] = {};
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    int ans = 0;
    {
        vector<pair<int, int>> vec;
        for(int i = 1; i <= n; i++){
            vec.emplace_back(x[i], y[i]);
            if(i == n or x[i+1]-x[i] > K){
                if(T == 1){
                    ans += solvemin(vec, K);
                } else {
                    ans += solvemax(vec, K);
                }
                vec.clear();
            }
        }
    }

    cout << ans << "\n";
    return 0;
}