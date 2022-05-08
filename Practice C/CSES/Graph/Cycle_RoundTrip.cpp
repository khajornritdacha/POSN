#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using pi = pair<int,int>;

int n,m,st;
bool vi[N];
vector<int> ans,G[N];

//https://cses.fi/problemset/task/1669

void dfs(int u, int p){
    //cout << u << "\n";
    if(vi[u]){
        if(st == 0){
            st = u;
            ans.push_back(u);
        }
        return;
    }
    vi[u] = true;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, u);
        
        if(st > 0){
            ans.push_back(u);
            if(st == u) st = -1;
            return;
        }
        
        if(st == -1) 
            return;
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vi[i]){
            dfs(i, -1);
            if(st == -1) break;
        }
    }

    if(st == 0){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << ans.size() << "\n";
        for(int an : ans) cout << an << " ";
        cout << "\n";
    }

    return 0;
}