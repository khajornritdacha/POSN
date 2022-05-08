#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
using tu3 = tuple<int,int,int>;
using tu4 = tuple<int,int,int,int>;
///https://codeforces.com/problemset/problem/609/E
int mx[N][22],pa[N][22],V,E,p[N],dep[N],mst;
bool use[N];
vector<pi> vec[N];
vector<tu3> rea(N);
vector<tu4> edge;

int fi(int x){
    if(p[x] == x) return x;
    return p[x] = fi(p[x]);
}

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u != v){
        p[v] = p[u];
        return true;
    }
    return false;
}

void dfs(int u, int p){
    pa[u][0] = p;
    for(int k=1; k<=20; k++){
        pa[u][k] = pa[pa[u][k-1]][k-1];
        mx[u][k] = max(mx[u][k-1], mx[pa[u][k-1]][k-1]);
    }
    for(auto [v, w] : vec[u]){
        if(v == p) continue;
        dep[v] = dep[u]+1;
        mx[v][0] = w;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    int res = 0;
    for(int k=20; k>=0; k--){
        if(dep[pa[u][k]] >= dep[v]){
            res = max(res, mx[u][k]);
            u = pa[u][k];
        }
    }
    if(u ==v)
        return res;
    //cout << "NOW : " << u << " " << res << "\n";
    for(int k=20; k>=0; k--){
        if(pa[u][k] != pa[v][k]){
            res = max({res, mx[u][k], mx[v][k]});
            u = pa[u][k];
            v = pa[v][k];
        }
    }
    if(DEBUG){
        cout << "MX : " << u << " " << res << "\n";
    }
    return max({res, mx[u][0], mx[v][0]});
}
main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    iota(p, p+V+1, 0);
    for(int i=1;  i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        rea[i] = {u, v, w};
        edge.emplace_back(w, u, v, i);
    }
    sort(edge.begin(), edge.end());
    for(auto [w, u, v, idx] : edge){
        if(uni(u, v)){
            mst += w;
            use[idx] = true;
            vec[u].emplace_back(v, w);
            vec[v].emplace_back(u, w);
        }
    }

    dfs(1, 1);

    if(DEBUG){
        for(int i=1; i<=V; i++){
            cout << "I " << i << " = ";
            for(int k=0; k<=3; k++){
                cout << pa[i][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        for(int i=1; i<=V; i++){
            cout << "I " << i << " = ";
            for(int k=0; k<=3; k++){
                cout << mx[i][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        for(int i=1; i<=E; i++){
            cout << "I : " << i << " = " << use[i] << "\n";
        }
    }
    for(int i=1; i<=E; i++){
        int u,v,w;
        tie(u, v, w) = rea[i];
        if(use[i]){
            cout << mst;
        }else{
            //cout << "GO : " << i << "\n";
            cout << mst-lca(u, v)+w;
        }
        cout << "\n";
    }
}
