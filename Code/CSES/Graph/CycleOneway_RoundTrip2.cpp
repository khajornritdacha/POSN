#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using pi = pair<int,int>;

int vi[N],n,m,st;
vector<int> G[N],ans;

//https://cses.fi/problemset/task/1678/

void dfs(int u){
    //cout << u << "\n";
    if(vi[u]){
        if(vi[u] == 1){
            st = u;
            ans.emplace_back(u);
        }
        return;
    }
    vi[u] = 1;
    for(int v : G[u]){
        dfs(v);

        if(st > 0){
            ans.emplace_back(u);
            if(u == st) st = -1;
            return;
        }

        if(st == -1) return;

    }
    vi[u] = 2;
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
    }

    for(int i = 1; i <= n; i++){
        if(!vi[i]){
            dfs(i);
            if(st != 0) break;
        }
    }

    if(st == 0){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for(int an : ans) cout << an << " ";
    }

    return 0;
}