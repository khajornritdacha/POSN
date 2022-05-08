#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10, INF = 1e9;
using pi = pair<int,int>;

int n,m,S,T,L;
priority_queue<pi, vector<pi>, greater<pi>> pq;
vector<pi> G[N];

void dij(int st, vector<int> &dis){
    dis[st] = 0;
    pq.emplace(0, st);
    while(!pq.empty()){
        auto [wa, u] = pq.top(); pq.pop();
        if(wa != dis[u]) continue;

        for(auto [v, w] : G[u]){
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> S >> T >> L;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    vector<int> dis(n+1, INF), rdis(n+1, INF);
    dij(S, dis);

    dij(T, rdis);

    if(dis[T] <= L){
        cout << T << " " << dis[T] << " 0\n";
    }else{
        int mn = INF, node = -1;
        for(int i = 1; i <= n; i++){
            if(dis[i] <= L and rdis[i] < mn){
                mn = rdis[i];
                node = i;
            }
        }
        cout << node << " " << dis[node] << " " << rdis[node] << "\n";
    }
}