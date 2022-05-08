#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using tu = tuple<ll,int,int,int>;
const int N = 8e4+10;
int n,m,L,Q,potion[N];
ll dis[N][15];
bool vi[N][15];
vector<pair<int,int>> vec[N];
priority_queue<tu, vector<tu>, greater<tu>> pq;
main(){
    cin >> n >> m >> L >> Q;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
    }
    for(int i=1; i<=n; i++) for(int j=0; j<=Q; j++) dis[i][j] = 1e18;
    for(int i=1; i<=L; i++){
        int x;
        cin >> x;
        potion[x]=i;
    }
    dis[1][0] = 0;
    pq.emplace(0, 1, 0, 0);
    while(!pq.empty()){
        auto [wa, u, k, la] = pq.top();
        pq.pop();
        if(vi[u][k]) continue;
        vi[u][k] = true;
        int go = la, ne = k;
        if(potion[u] and k<Q and la!=potion[u]){
            ne++;
            go = potion[u];
        }
        for(auto [v, w] : vec[u]){
            if(!vi[v][ne] and dis[u][k]+(w/(1<<ne)) < dis[v][ne]){
                dis[v][ne] = wa+(w/(1<<ne));
                pq.emplace(dis[v][ne], v, ne, go);
            }
        }
    }
    ll ans = 1e18;
    for(int i=0; i<=Q; i++) ans = min(ans, dis[n][i]);
    cout << ans;
}
