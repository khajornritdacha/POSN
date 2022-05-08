#include <bits/stdc++.h>
using namespace std;

const int N = 2510, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;

int n,m,dis[N],S,T,P,pa[N];
bool vi[N];
vector<pi> G[N];
priority_queue<pi> pq;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    cin >> S >> T >> P;

    for(int i = 1; i <= n; i++) dis[i] = -INF;
    dis[S] = 0;

    pq.emplace(dis[S], S); //Prim's algo for finding maximum spanning tree
    while(!pq.empty()){
        auto [wa, u] = pq.top(); pq.pop();
        if(vi[u]) continue;
        vi[u] = true;
        if(u == T) break;

        for(auto [v, w] : G[u]){
            if(!vi[v] and w > dis[v]){
                dis[v] = w;
                pa[v] = u;
                pq.emplace(dis[v], v);
            }
        }
    }

    int now = T, mn = INF;
    while(now != S){
        mn = min(mn, dis[now]);
        now = pa[now];
    }

    int k = (P+mn-2)/(mn-1); //the number of guide
    cout << k << "\n";

    return 0;
}