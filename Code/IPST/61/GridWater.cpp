#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, LOG = 25;

int dep[N],cp[N],pa[N][LOG+1],mx[N][LOG+1],id,R,C,num[410][410];
bool JOMNOINO1[N];
vector< pair<int,int> > G[N];
vector< tuple<int,int,int> > edge;

int fi(int x){
    return cp[x] = (x == cp[x] ? x : fi(cp[x]));
}

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u != v){
        cp[u] = v;
        return true;
    }
    return false;
}

void dfs(int u, int p){
    dep[u] = dep[p]+1;
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        pa[v][0] = u;
        mx[v][0] = w;
        dfs(v, u);
    }
}

int solve(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int res = 0;
    for(int k = 25; k >= 0; k--){
        if(dep[pa[u][k]] >= dep[v]){
            res = max(res, mx[u][k]);
            u = pa[u][k];
        }
    }
    if(u == v) return res;
    for(int k = 25; k >= 0; k--){
        if(pa[u][k] != pa[v][k]){
            res = max({res, mx[u][k], mx[v][k]});
            u = pa[u][k];
            v = pa[v][k];
        }
    }
    res = max({res, mx[u][0], mx[v][0]});
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++) for(int j = 1; j <= C; j++) num[i][j] = ++id;

    for(int k = 1, i = 1; k <= 2*R-1; k++){
        int w;
        if(k&1){
            for(int j = 1; j < C; j++){
                cin >> w;
                edge.emplace_back(w, num[i][j], num[i][j+1]);
            }
        }else{
            for(int j = 1; j <= C; j++){
                cin >> w;
                edge.emplace_back(w, num[i][j], num[i+1][j]);
            }
            i++;
        }
    }

    for(int i = 1; i <= id; i++)
        cp[i] = i;

    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++){
        auto [w, u, v] = edge[i];
        if(uni(u, v)){
            JOMNOINO1[i] = true;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
    }

    dfs(1, 0);
    for(int k = 1; k <= LOG; k++){
        for(int u = 1; u <= id; u++){
            pa[u][k] = pa[pa[u][k-1]][k-1];
            mx[u][k] = max(mx[u][k-1], mx[pa[u][k-1]][k-1]);
        }
    }

    int ans = 1e9;
    for(int i = 0; i < edge.size(); i++){
        if(JOMNOINO1[i]) continue;
        auto [w, u, v] = edge[i];
        //cout << w << "\n";
        ans = min(ans, w-solve(u, v));
    }
    cout << ans << "\n";
    return 0;
}
