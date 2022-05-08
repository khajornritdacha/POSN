#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<ll, ll>;
using tu = tuple<ll, int, int>;

const ll INF = 1e18;

int n,m,D[N];
pi dis[N][2], ans2;
priority_queue<tu, vector<tu>, greater<tu>> pq;
vector<pi> G[N];

//https://codeforces.com/gym/100812/problem/G

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){ dis[i][0] = dis[i][1] = pi(INF, -1); }

    for(int i = 1; i <= n; i++){
        cin >> D[i];
        if(D[i]){
            dis[i][0] = pi(0, i);
            pq.emplace(0, i, i);
        }
    }

    ll ans = INF;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        if(D[u] and D[v]){
            if(w < ans){
                ans = w;
                ans2 = pi(u, v);
            }
        }
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    while(!pq.empty()){
        auto [wa, pa, u] = pq.top(); pq.pop();
        if((dis[u][0] != pi(wa, pa)) and (dis[u][1] != pi(wa, pa))) continue;

        for(auto [v, w] : G[u]){
            if(wa + w < dis[v][0].first){
                if(dis[v][0].second != pa)
                    dis[v][1] = dis[v][0];
                
                dis[v][0] = pi(wa+w, pa);
                pq.emplace(dis[v][0].first, pa, v);
            } 
            
            else if(wa + w < dis[v][1].first and pa != dis[v][0].second){
                dis[v][1] = pi(wa+w, pa);
                pq.emplace(dis[v][1].first, pa, v);
            }
        }
    }

    // cout << "\n";
    for(int i = 1; i <= n; i++){
        assert(dis[i][1].second == -1 or (dis[i][0].second != dis[i][1].second));
        if(D[i] or dis[i][1].first >= INF) continue;
        ll tmp = dis[i][0].first + dis[i][1].first;
        if(tmp < ans){
            ans = tmp;
            ans2 = pi(dis[i][0].second, dis[i][1].second);
        }
        // cout << i << " " << dis[i][0].first << " "  << dis[i][1].first << "\n";
    }

    if(ans >= INF){
        cout << "No luck at all\n";
    } else {
        cout << ans << "\n";
        cout << ans2.first << " " << ans2.second << "\n";
    }
    return 0;
}