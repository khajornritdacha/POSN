#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using tu = tuple<long long, int, int>;
using pi = pair<ll, ll>;
const int N = 1e4+10;

///https://www.spoj.com/problems/TRAFFICN/

int n,m,K,St,Ed;
priority_queue<tu, vector<tu>, greater<tu>> pq;
vector<pi> G[N][2];

void test_case(){
    cin >> n >> m >> K >> St >> Ed;
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        G[u][0].emplace_back(v, w);
    }
    for(int i = 1; i <= K; i++){
        int u,v,w; cin >> u >> v >> w;
        G[u][1].emplace_back(v, w);
        G[v][1].emplace_back(u, w);
    }

    vector<vector<ll>> dis(n+5, vector<ll>(2, 1e18));
    dis[St][0] = 0;
    pq.emplace(0, St, 0);
    while(!pq.empty()){
        auto [wa, u, code] = pq.top(); pq.pop();
        if(wa != dis[u][code]) continue;
        for(auto [v, w] : G[u][0]){
            if(dis[u][code]+w < dis[v][code]){
                dis[v][code] = dis[u][code]+w;
                pq.emplace(dis[v][code], v, code);
            }
        }
        if(code == 0){
            for(auto [v, w] : G[u][1]){
                if(dis[u][0]+w < dis[v][1]){
                    dis[v][1] = dis[u][0]+w;
                    pq.emplace(dis[v][1], v, 1);
                }
            }
        }
    }
    if(dis[Ed][1] == 1e18 and dis[Ed][0] == 1e18){
        cout << "-1\n";
    }else{
        cout << min(dis[Ed][0], dis[Ed][1]) << "\n";
    }

    for(int i = 0; i <= n; i++){
        G[i][0].clear(); G[i][1].clear();
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
