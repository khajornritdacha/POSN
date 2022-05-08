#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;

int n,Q,pa[N],tin[N],tout[N],t,dep[N];
vector<int> G[N];

void dfs(int u, int p){
    tin[u] = ++t;
    pa[u] = p;
    for(int v : G[u]){
        if(v == p) continue;
        dep[v] = dep[u]+1;
        dfs(v, u);
    }
    tout[u] = ++t;
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dep[1] = 1;
    dfs(1, 0);

    /*for(int i = 1; i <= n; i++){
        cout << tin[i] << " \n"[i==n];
    }
    for(int i = 1; i <= n; i++){
        cout << tout[i] << " \n"[i==n];
    }*/

    while(Q--){
        int m, v = 0;
        cin >> m;
        bool ok = true;
        vector<int> vec;
        for(int i = 1; i <= m; i++){
            int u; cin >> u;
            if(dep[u] > dep[v]) v = u;
            vec.emplace_back(u);
        }

        //cout << v << "\n";
        for(int &it : vec){
            if(it != 1 and it != v) it = pa[it];
            ok &= (tin[it] <= tin[v] and tout[v] <= tout[it]);
        }

        if(ok)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}
