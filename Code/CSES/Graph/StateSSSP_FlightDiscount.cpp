#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
using ll = long long;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<ll,int,int>;

int n,m;
vector<pi> G[N];
priority_queue<tu, vector<tu>, greater<tu>> pq;
ll dis[N][2];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
    }

    for(int i = 1; i <= n; i++) dis[i][0] = dis[i][1] = INF;

    dis[1][0] = 0;
    pq.emplace(0, 1, 0);
    while(!pq.empty()){
        auto [wa, u, cd] = pq.top(); pq.pop();
        if(wa != dis[u][cd]) continue;

        for(auto [v, w] : G[u]){
            if(dis[u][cd] + w < dis[v][cd]){
                dis[v][cd] = dis[u][cd] + w;
                pq.emplace(dis[v][cd], v, cd);
            }
            if(cd == 0){
                if(dis[u][0] + w/2 < dis[v][1]){
                    dis[v][1] = dis[u][0] + w/2;
                    pq.emplace(dis[v][1], v, 1);
                }
            }
        }
    }

    cout << dis[n][1] << "\n";
    return 0;
}
