#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int V, E, pa[N];
vector<tuple<int, int, int>> edges;

int fi(int u){
    // Shorten ver
    // return pa[u] = (pa[u] != u ? fi(pa[u]) : u);
    if(pa[u] != u) return pa[u] = fi(pa[u]);
    return u;
}

bool unite(int u, int v){
    int hu = fi(u), hv = fi(v);
    if(hu != hv){
        pa[hv] = hu;
        return true;
    }
    return false;
}

int main(void){
    cin >> V >> E;
    for(int i = 1; i <= V; i++) pa[i] = i;
    for(int i = 0; i < E; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    long long ans = 0;
    for(auto [w, u, v] : edges){
        if(unite(u, v)){
            ans += w;
        }
    }
    cout << ans << "\n";


    return 0;
}

/*
5 6
1 2 2
1 3 5
1 4 6
2 4 8
3 4 3
4 5 2
*/