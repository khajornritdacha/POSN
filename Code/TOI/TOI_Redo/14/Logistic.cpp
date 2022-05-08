#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
using pi = pair<int,int>;
using tu = tuple<int,int,int,int>;

int n,P[N],dis[N][N][2],S,D,F,m;
vector<pi> G[N];
priority_queue<tu, vector<tu>, greater<tu>> pq;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> P[i];
        G[i].emplace_back(i, 0); //create edge to itself with weight 0
    }
    cin >> S >> D >> F;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }  

    for(int i = 0; i <= n; i++) for(int k = 0; k <= F; k++) dis[i][k][0] = dis[i][k][1] = INF;
    dis[S][0][0] = 0;
    pq.emplace(0, S, 0, 0);
    while(!pq.empty()){
        auto [wa, u, cf, b] = pq.top(); pq.pop();
        if(dis[u][cf][b] != wa) continue;
        if(u == D and cf == F and b) break; ///time saver
        for(auto [v, w] : G[u]){
            for(int k = 0; cf+k <= F; k++){
                if(cf+k-w < 0) continue;

                if(dis[u][cf][b] + k*P[u] < dis[v][cf+k-w][b]){
                    dis[v][cf+k-w][b] = dis[u][cf][b] + k*P[u];
                    pq.emplace(dis[v][cf+k-w][b], v, cf+k-w, b);
                }

                if(b == 0 and dis[u][cf][0] < dis[v][cf+k-w][1]){
                    dis[v][cf+k-w][1] = dis[u][cf][0];
                    pq.emplace(dis[v][cf+k-w][1], v, cf+k-w, 1);
                }
            }
        }
    }

    cout << dis[D][F][1] << "\n";
    return 0;
}