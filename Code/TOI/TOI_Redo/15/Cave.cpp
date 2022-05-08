#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2010, INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,P,U,m,dis[N][N];
vector<pi> G[N],res;
priority_queue<tu, vector<tu>, greater<tu>> pq;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> P >> U >> m;
    P++; U++;

    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        u++, v++;
        G[u].emplace_back(v, w);
    }

    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dis[i][j] = INF;

    dis[P][0] = 0;
    pq.emplace(0, P, 0);

    while(!pq.empty()){
        auto [wa, u, t] = pq.top(); pq.pop();
        if(dis[u][t] != wa) continue;
        if(t == n) continue;

        int go = t+(u != P);
        assert(go <= n);
        for(auto [v, w] : G[u]){
            if(dis[u][t] + w < dis[v][go]){
                dis[v][go] = dis[u][t]+w;
                pq.emplace(dis[v][go], v, go);
            }
        }
    }

    int la = INF;
    for(int i = 0; i <= n; i++){
        if(dis[U][i] != INF and dis[U][i] < la){
            res.emplace_back(dis[U][i], i);
            la = dis[U][i];
        }
        //cout << dis[U][i] << " ";
    }
    //cout << "\n";

    /*cout << "RES\n";
    for(auto [val, mul] : res){
        cout << val << " " << mul << "\n";
    }
    cout << "\n";*/

    int Q; cin >> Q;
    while(Q--){
        int h; cin >> h;
        int ans = INF;
        for(auto [val, mul] : res){
            ans = min(ans, val+mul*h);
        }
        cout << ans << "\n";
    }

    return 0;
}
