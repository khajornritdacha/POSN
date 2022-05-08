#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e5+10;
using tu = tuple<int,int,int>;

///https://www.spoj.com/problems/KOICOST/

int n,m,pa[N],sz[N];
vector<tu> edge;
ll mod = 1e9;

int fi(int x){
    return pa[x] = (pa[x] == x) ? x : fi(pa[x]);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }

    for(int i = 1; i <= n; i++){
        pa[i] = i;
        sz[i] = 1;
    }

    sort(edge.rbegin(), edge.rend());

    ll ans = 0, cur_pair = 0;
    for(auto [w, u, v] : edge){
        u = fi(u), v = fi(v);
        if(u != v){
            cur_pair += 1ll*sz[u]*sz[v];
            cur_pair %= mod;
            pa[u] = v;
            sz[v] += sz[u];
        }
        ans += 1ll*w*cur_pair;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}
