#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,Q,pa[N][22],dep[N];
vector<int> vec[N];

void dfs(int u, int p){
    pa[u][0] = p;
    for(int k=1; k<=20; k++){
        pa[u][k] = pa[pa[u][k-1]][k-1];
    }
    for(int v : vec[u]){
        if(v == p) continue;
        dep[v] = dep[u]+1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int k=20; k>=0; k--){
        if(dep[pa[u][k]] >= dep[v]){
            u = pa[u][k];
        }
    }
    if(u == v)
        return u;
    for(int k=20; k>=0; k--){
        if(pa[u][k] != pa[v][k]){
            u = pa[u][k];
            v = pa[v][k];
        }
    }
    return pa[u][0];
}

main(){
    cin >> n >> Q;
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        vec[x].emplace_back(i);
    }
    dfs(1, 1);

    for(int i=1,lim=ceil(log2(n)); i<=n; i++){
        cout << "I " << i << " = ";
        for(int k=0; k<=lim; k++){
            cout << pa[i][k] << " ";
        }
        cout << "\n";
    }

    while(Q--){
        int u,v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

}
