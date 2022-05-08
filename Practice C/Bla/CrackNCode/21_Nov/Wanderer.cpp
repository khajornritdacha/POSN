#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;

int n,m,Q,dis[N][15];
vector<pi> G[N];
priority_queue<tu, vector<tu>, greater<tu>> pq;

int main(void){
    cin >> n >> m >> Q;

    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= Q; j++){
            dis[i][j] = 2e9;
        }
    }

    dis[1][Q] = 0;
    pq.emplace(0, 1, Q);
    while(!pq.empty()){
        auto [wa, u, t] = pq.top(); pq.pop();
        if(dis[u][t] != wa) continue;
        for(auto [v, w] : G[u]){
            if(t == Q){
                if(dis[u][t] + w < dis[v][t]){
                    dis[v][t] = dis[u][t] + w;
                    pq.emplace(dis[v][t], v, t);
                }
                if(dis[u][t] < dis[v][1]){
                    dis[v][1] = dis[u][t];
                    pq.emplace(dis[v][1], v, 1);
                }
            }else{
                if(dis[u][t] + w < dis[v][t+1]){
                    dis[v][t+1] = dis[u][t] + w;
                    pq.emplace(dis[v][t+1], v, t+1);
                }
            }
        }
    }

    int ans = 2e9;
    for(int i = 1; i <= Q; i++) ans = min(ans, dis[n][i]);
    cout << ans << "\n";

    return 0;
}
