#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
using ll = long long;
const ll INF = 1e18;

int n,m;
ll dis[N];
vector<tuple<int,int,int>> edge;

void bellman_ford(){
    for(int i = 1; i < n; i++){
        for(auto [u, v, w] : edge){
            if(dis[u] <= -INF) continue;
            if(dis[u] + w > dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(auto [u, v, w] : edge){
            if(dis[u] == -INF) continue; ///Very Important Line
            if(dis[u] >= INF or dis[u] + w > dis[v]){
                dis[v] = INF;
            }
        }
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        edge.emplace_back(u, v, w);
    }

    for(int i = 2; i <= n; i++) dis[i] = -INF;
    bellman_ford();

    ll ans = dis[n];
    if(dis[n] == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
