#include <bits/stdc++.h>
using namespace std;


const int N = 2e5+10;

int n,m,cp[N];
vector<tuple<int,int,int>> edge;

//https://atcoder.jp/contests/abc218/tasks/abc218_e

int fi(int x){ return cp[x] = (cp[x] == x) ? x : fi(cp[x]); }

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v) return false;
    cp[v] = u;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cp[i] = i;

    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }

    sort(edge.begin(), edge.end());
    long long ans = 0;
    for(auto [w, u, v] : edge){
        if(!uni(u, v)){
            //cout << u << " " << v << "\n";
            if(w > 0) ans += w;
        }
    }

    cout << ans << "\n";

    return 0;
}