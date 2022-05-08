#include <bits/stdc++.h>
using namespace std;

const int N = 510;
using ll = long long;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<ll,int,int>;

///https://www.e-olymp.com/en/problems/1453

int n,m,Q;
ll dis[N];
vector<tu> edge;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        edge.emplace_back(u, v, w);
    }

    for(int i = 2; i <= n; i++) dis[i] = INF;

    for(int i = 1; i < n; i++){
        for(auto [u, v, w] : edge){
            if(dis[u] >= INF) continue; ///Must include this line
            dis[v] = min(dis[v], dis[u] + w);
        }
    }

    for(int i = 1; i <= n; i++){
        if(dis[i] >= INF) dis[i] = 30000;
        cout << dis[i] << " \n"[i==n];
    }
    return 0;
}
