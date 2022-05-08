#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 1e9, LOG = 30;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int n,m,cp[N],cnt;
vector<tu> edge;

int fi(int x){ return cp[x] = (cp[x] == x) ? x : fi(cp[x]); }

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v) return false;
    cp[u] = v;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cp[i] = i;
    cnt = n;

    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }
    sort(edge.begin(), edge.end());

    ll ans = 0;
    for(auto [w, u, v] : edge){
        if(uni(u, v)){
            ans += w;
            cnt--;
        }
    }

    if(cnt != 1) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";

    return 0;
}