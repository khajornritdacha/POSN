#include <bits/stdc++.h>
using namespace std;

const int N = 510;
using ll = long long;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<ll,int,int>;

int n,m,Q;
ll dis[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> Q;

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = (i == j) ? 0 : INF;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min(dis[u][v], 1ll*w); ///in case of parallel edges
    }

    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);

    while(Q--){
        int u, v; cin >> u >> v;
        ll ans = dis[u][v];
        if(dis[u][v] >= INF) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
