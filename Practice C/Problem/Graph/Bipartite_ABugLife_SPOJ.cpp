#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int co[N],n,m;
vector<int> G[N];

///https://www.spoj.com/problems/BUGLIFE/
///Bipartite graph

bool bi(int u, int wa){
    if(co[u]) return co[u] == wa;
    co[u] = wa;
    for(int v : G[u]){
        if( bi(v, (wa == 1) ? 2 : 1) == false)
            return false;
    }
    return true;
}

void test_case(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(!co[i]){
            ok &= bi(i, 1);
        }
    }

    for(int i = 0; i <= n; i++){ co[i] = 0; G[i].clear(); }

    if(ok) cout << "No suspicious bugs found!\n";
    else cout << "Suspicious bugs found!\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Scenario #" << i << ":\n";
        test_case();
    }

    return 0;
}
