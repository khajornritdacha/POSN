#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int idx,n,K,sz[N],order[N];
ll sum[N],ans,mx[N][210],dp[N][210];
vector<int> G[N];

//https://www.hackerrank.com/challenges/tree-pruning/problem
//dp(i, k) := the maximum of negative number that it can be removed with k removed operation
//turn subtree into array
//dp(i, k) = max(not choose -> dp(i-1, k), choose current subtree -> dp(i - size[index of subtree[i]], k-1) + sum[index of subtree[i]] )

void dfs(int u, int p){
    sz[u] = 1;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        sum[u] += sum[v];
    }
    order[++idx] = u;
}

int main(void){
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> sum[i];
        ans += sum[i];
        sum[i] *= -1;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }    

    dfs(1, -1);

    for(int k = 1; k <= K; k++){
        for(int i = 1; i <= n; i++){
            assert(i-sz[order[i]] >= 0);
            dp[i][k] = max(dp[i-1][k], dp[i-sz[ order[i] ] ][k-1] + sum[order[i]]);
        }
    }

    ans += dp[n][K];
    cout << max(0ll, ans) << "\n";
    return 0;
}
