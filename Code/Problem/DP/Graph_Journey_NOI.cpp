#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;

int n, M, H, dp[N][410];
vector<pair<int, int>> G[N];

//https://oj.uz/problem/view/NOI18_journey

//dp(v, m+k) += dp(u, m); mn <= k < M-mn
//turn into quick sum

//no need to find topological order because i has to perform before j if i < j

inline void add(int &a, int b){
    if(a + b >= 500'000'001) a = 500000001;
    else a += b;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M >> H;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < H; j++){
            int v, mn; cin >> v >> mn;
            // assert(v > i);
            if(v > i)
                G[i].emplace_back(v, mn);
        }
    }

    dp[0][0] = 1;
    for(int u = 0; u < n-1; u++){
        for(int m = 1; m < M; m++){
            add(dp[u][m], dp[u][m-1]);
        }

        for(auto [v, mn] : G[u]){
            for(int m = 0; m+mn < M; m++){
                add(dp[v][m+mn], dp[u][m]);
            }
        }
    }

    for(int m = 0; m < M; m++) cout << dp[n-1][m] << " ";
    cout << "\n";


    return 0;
}
