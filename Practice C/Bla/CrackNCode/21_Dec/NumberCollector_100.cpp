#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

ll n, m, K, a[N], deg[N], dp[N][105], mod = 1e9+7, cnt[N];
queue<int> qq;
vector<int> G[N];

void add(ll &A, ll x){
    A += x;
    if(A >= mod) A -= mod;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> K;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];

    qq.emplace(1);
    dp[1][0] = 1;
    while(!qq.empty()){
        int u = qq.front(); qq.pop();

        ll tmp = 0;
        for(int k = max(1ll, a[u]-K); k <= a[u]+K and k <= 100; k++){
            add(tmp, dp[u][k]);
        }
        add(dp[u][a[u]], dp[u][0]+tmp);
        for(int v : G[u]){
            if(++cnt[v] == deg[v]) qq.emplace(v);
            for(int k = 0; k <= 100; k++){
                add(dp[v][k], dp[u][k]);
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) for(int k = 1; k <= 100; k++) add(ans, dp[i][k]);
    cout << ans << "\n";

    // for(int i = 1; i <= n; i++){
    //     for(int k = 0; k <= 6; k++) cout << dp[i][k] << " ";
    //     cout << "\n";
    // }
    


    return 0;
}