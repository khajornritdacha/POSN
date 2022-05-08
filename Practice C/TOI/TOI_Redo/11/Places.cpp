#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,m,pa[N];
vector<tu> edge;

int fi(int x){ return pa[x] = (pa[x] == x) ? x : fi(pa[x]); }

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u != v){
        pa[u] = v;
        return true;
    }
    return false;
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge.emplace_back(w-1, u, v);
    }

    for(int i = 1; i <= n; i++) pa[i] = i;

    sort(edge.rbegin(), edge.rend());

    ll ans = 0;
    for(auto [w, u, v] : edge) if(uni(u, v)) ans += w;

    cout << ans << "\n";
    return 0;   
}