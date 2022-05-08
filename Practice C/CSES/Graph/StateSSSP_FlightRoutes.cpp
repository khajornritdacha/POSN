#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;
const ll INF = 1e18;
using tu = tuple<ll, int, int>;

int n,m,K;
vector<pair<int,int>> G[N];
ll dis[N][15];
priority_queue<tu, vector<tu>, greater<tu> > pq;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> K;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
    }

    for(int i = 1; i <= n; i++) for(int j = 0; j < K; j++) dis[i][j] = INF;

    dis[1][0] = 0;
    pq.emplace(0, 1, 0);
    while(!pq.empty()){
        auto [wa, u, cd] = pq.top(); pq.pop();
        if(wa != dis[u][cd]) continue;

        //cout << wa << " " << u << " " << cd << " " << dis[u][cd] << "\n";
        for(auto [v, w] : G[u]){
            ll tmp = dis[u][cd] + w;
            //cout << "V: " << v << " " << w << " " << tmp << "\n";
            for(int k = 0; k < K; k++){
                if(tmp < dis[v][k]){
                    swap(tmp, dis[v][k]);
                    pq.emplace(dis[v][k], v, k);
                }
            }
        }
    }

    for(int k = 0; k < K; k++)
        cout << dis[n][k] << " ";
    cout << "\n";
    return 0;
}
