#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int n,nL,nD;
vector<int> cmp,G[N],D[N];
bool vi[N];

//https://codeforces.com/problemset/problem/177/C2

void dfs(int u){
    vi[u] = true;
    cmp.emplace_back(u);
    for(int v : G[u]){
        if(!vi[v]) dfs(v);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> nL;
    for(int i = 1; i <= nL; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    cin >> nD;
    for(int i = 1; i <= nD; i++){
        int u, v; cin >> u >> v;
        D[u].emplace_back(v);
        D[v].emplace_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vi[i]) continue;

        cmp.clear();
        dfs(i);
        
        set<int> ss = {cmp.begin(), cmp.end()};
        bool ok = true;
        
        for(int u : cmp){
            for(int v : D[u]){
                if(ss.count(v)){
                    ok = false;
                    break;
                }
            }
        }
        
        if(ok) ans = max(ans, (int)cmp.size());
    }

    cout << ans << "\n";
    return 0;
}