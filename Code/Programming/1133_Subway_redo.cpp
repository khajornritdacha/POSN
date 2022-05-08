#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, M = 510, INF = 1e9;

int n, m, Q, dis[M][M];
vector<int> ele[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int sz; cin >> sz;
        for(int j = 1; j <= sz; j++){
            int u; cin >> u;
            ele[u].emplace_back(i);
        }
    }

    for(int i = 1; i <= m; i++) for(int j = 1; j <= m; j++) if(i != j) dis[i][j] = INF;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < ele[i].size(); j++){
            for(int k = j+1; k < ele[i].size(); k++){
                int u = ele[i][j], v = ele[i][k];
                dis[u][v] = min(dis[u][v], 1);
                dis[v][u] = min(dis[v][u], 1);
            }
        }
    }

    for(int k = 1; k <= m; k++) for(int i = 1; i <= m; i++) for(int j = 1; j <= m; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    cin >> Q;
    while(Q--){
        int u, v, ans = INF; cin >> u >> v;
        
        for(int i = 0; i < ele[u].size(); i++){
            for(int j = 0; j < ele[v].size(); j++){
                ans = min(ans, dis[ele[u][i]][ele[v][j]]);
            }
        }

        if(ans == INF){
            cout << "impossible\n";
        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}