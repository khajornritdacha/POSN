#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 1e9;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

//https://www.spoj.com/problems/SAMER08A/

int dis[N], n, m;
bool vi[N], ban[10010];
vector<tu> G[N];
vector<pi> bt[N];
priority_queue<pi, vector<pi>, greater<pi>> pq;

void dij(int st){
    for(int i = 0; i <= n; i++) dis[i] = INF;
    dis[st] = 0;
    pq.emplace(0, st);
    while(!pq.empty()){
        auto [wa, u] = pq.top(); pq.pop();
        if(wa != dis[u]) continue;

        for(auto [v, w, idx] : G[u]){
            if(ban[idx]) continue;
            if(dis[u] + w < dis[v]){
                bt[v].clear();
                bt[v].emplace_back(u, idx);
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
            } else if (dis[u] + w == dis[v]){
                bt[v].emplace_back(u, idx);
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        cin >> n >> m;
        if(n == 0 and m == 0) break;

        int S, D; cin >> S >> D;
        for(int i = 0; i < m; i++){
            int u, v, w; cin >> u >> v >> w;
            G[u].emplace_back(v, w, i);
        }

        dij(S);

        queue<int> qq;
        qq.emplace(D);
        while(!qq.empty()){
            int u = qq.front(); qq.pop();
            vi[u] = true;

            for(auto [v, idx] : bt[u]){
                ban[idx] = true;
                if(!vi[v]){
                    vi[v] = true;
                    qq.emplace(v);
                }
            }
        }
    
        dij(S);

        if(dis[D] >= INF) dis[D] = -1;
        cout << dis[D] << "\n";

        for(int i = 0; i <= n; i++){ G[i].clear(), bt[i].clear(), vi[i] = false; }
        for(int i = 0; i <= m; i++){ ban[i] = false; }
    }
    return 0;
}
