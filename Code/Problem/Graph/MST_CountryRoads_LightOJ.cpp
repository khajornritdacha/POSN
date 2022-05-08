#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 510;
const int INF = 1e9;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

//https://lightoj.com/problem/country-roads

int ans[N],dis[N];
bool vi[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int n, m; cin >> n >> m;
        vector<vector<pi>> G(n);
        for(int i = 1; i <= m; i++){
            int u, v, w; cin >> u >> v >> w;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        int st; cin >> st;

        for(int i = 0; i <= n; i++) dis[i] = ans[i] = INF, vi[i] = false;
        dis[st] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.emplace(dis[st], st);
        while(!pq.empty()){
            auto [wa, u] = pq.top(); pq.pop();
            if(vi[u]) continue;

            vi[u] = true;
            for(auto [v, w] : G[u]){
                if(!vi[v] and w < dis[v]){
                    dis[v] = w;
                    pq.emplace(dis[v], v);
                }
            }
        }

        ans[st] = 0;
        queue<int> qq;
        qq.emplace(st);
        while(!qq.empty()){
            int u = qq.front(); qq.pop();

            for(auto [v, w] : G[u]){
                if(ans[v] >= INF and w == dis[v]){
                    ans[v] = max(ans[u], w);
                    qq.emplace(v);
                }
            }        
        }

        //for(int i = 0; i < n; i++) cout << dis[i] << " " << ans[i] << "\n";

        cout << "Case " << tt << ":\n";
        for(int i = 0; i < n; i++){
            if(ans[i] >= INF) cout << "Impossible\n";
            else cout << ans[i] << "\n";
        }
    }
    
    return 0;
}
