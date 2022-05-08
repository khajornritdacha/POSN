#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 2e5+10;
const ll INF = 1e18;
using pi = pair<ll,int>;
using tu = tuple<ll,int,int>;

int n,m,mn[N],mx[N];
ll dis[N], num[N], mod = 1e9+7;
vector<pi> G[N];
priority_queue<pi, vector<pi>, greater<pi>> pq;

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
    }

    //minimum element, number of ways, minimum number of edge, maximum number of edge
    for(int i = 1; i <= n; i++) dis[i] = INF;
    num[1] = 1;
    mn[1] = mx[1] = 0;
    dis[1] = 0;
    pq.emplace(dis[1], 1);
    while(!pq.empty()){
        auto [wa, u] = pq.top(); pq.pop();
        if(dis[u] != wa) continue;

        for(auto [v, w] : G[u]){
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                num[v] = num[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                pq.emplace(dis[v], v);
            } else if (dis[u] + w == dis[v]){
                num[v] = (num[v] + num[u])%mod;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }

    cout << dis[n] << " " << num[n] << " " << mn[n] << " " << mx[n] << "\n";

    // for(int i = 1; i <= n; i++){
    //     cout << dis[i] << " " << num[i] << " " << mn[i] << " " << mx[i] << "\n";
    // }
    
    return 0;
}
