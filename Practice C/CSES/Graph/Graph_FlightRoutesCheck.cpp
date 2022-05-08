#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<bool> vi[2];
vector<vector<int>> vec[2];
void setIO(string name=""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void dfs(int u, int code){
    vi[code][u] = true;
    for(int v : vec[code][u]){
        if(!vi[code][v]){
            dfs(v, code);
        }
    }
}
main(){
    setIO();
    cin >> n >> m;
    vec[0].resize(n+1), vec[1].resize(n+1);
    vi[0].assign(n+1, false), vi[1].assign(n+1, false);
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        vec[0][u].emplace_back(v);
        vec[1][v].emplace_back(u);
    }
    dfs(1, 0);

    dfs(1, 1);

    bool ans = true;
    for(int i=1; i<=n; i++){
        ans &= vi[0][i] && vi[1][i];
    }
    if(ans){
        cout << "YES\n";
    }else{
        cout << "NO\n";
        for(int i=1; i<=n; i++){
            if(!vi[0][i])
                cout << 1 << " " << i << "\n";
        }
        for(int i=1; i<=n; i++){
            if(!vi[1][i])
                cout << i << " " << 1 << "\n";
        }
    }
}
