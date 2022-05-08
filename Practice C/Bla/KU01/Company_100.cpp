#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int n, dp[N];
vector<int> G[N];
bool vi[N];

int dfs(int u){
    if(vi[u]) return dp[u];
    vi[u] = true;
    for(int v : G[u]){
        dp[u] += dfs(v)+1;
    }
    return dp[u];
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int m; cin >> m;
        for(int j = 1; j <= m; j++){
            int x, y; cin >> x >> y;
            if(y > 50){
                G[x].emplace_back(i);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dfs(i));
    }

    cout << ans << "\n";
    return 0;
}