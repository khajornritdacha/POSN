#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<ll, ll>;
vector<pi> vec[N];
int n,Q,dp[N];

void dfs(int u, int p){
    for(auto [v, w] : vec[u]){
        if(v == p) continue;
        dp[v] = dp[u]^w;
        dfs(v, u);
    }
}
///define dp(u) = xor sum from 1 to u
/// A^A = 0 or the intersection part will be omitted
///hence, xor sum from u to v = (dp(u) ^ dp(v)) -> becuz the intersection part is path from 1 to u will be omitted and the left one is from path u to v
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=1; i<n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }
    dfs(1, -1);
    while(Q--){
        int u,v;
        cin >> u >> v;
        cout << (dp[u]^dp[v]) << "\n";
    }
}
