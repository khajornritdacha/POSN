#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,m,pa[N];
vector<tu> edge;

int fi(int x){ return (pa[x] < 0) ? x : fi(pa[x]); } //without path compression

bool uni(int u, int v){
    //cout << u << " " << v << " " << pa[u] << " " << pa[v] << " " << pa[pa[u]] << " " << pa[pa[v]] << "\n";
    u = fi(u), v = fi(v);
    if(u != v){
        if(-pa[v] > -pa[u]) swap(v, u); //u's size will always be greater than that of v so swap between u and v if v's size is greater
        pa[u] += pa[v];
        pa[v] = u;
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

    for(int i = 1; i <= n; i++) pa[i] = -1; //-1 means i is root of its component and its size is 1

    sort(edge.rbegin(), edge.rend());

    ll ans = 0;
    for(auto [w, u, v] : edge) if(uni(u, v)) ans += w;

    cout << ans << "\n";
    return 0;   
}