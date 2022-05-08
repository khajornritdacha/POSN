#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 1e9;

using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n, m, cp[N];
vector<tu> edge;
bool ful[N];

//https://codeforces.com/contest/875/problem/F

int fi(int x){ return cp[x] = (cp[x] == x) ? x : fi(cp[x]); }

//see princes as node and princesses as edge
//in each component we can add a princess at most 1 (array ful)

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v){
        if(!ful[u]){
            ful[u] = true;
            return true;
        }
        return false;
    } else {
        cp[u] = v;
        if(ful[u] and ful[v]) return false;
        if(ful[u] or ful[v]){ ful[u] = ful[v] = true; return true; } //if u is full or v is full
        return true;
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }

    sort(edge.rbegin(), edge.rend());

    for(int i = 1; i <= n; i++){ cp[i] = i, ful[i] = 0; }

    long long ans = 0;
    for(auto [w, u, v] : edge){
        if(uni(u, v)){
            ans += w;
        }
    }

    cout << ans << "\n";

    return 0;
}