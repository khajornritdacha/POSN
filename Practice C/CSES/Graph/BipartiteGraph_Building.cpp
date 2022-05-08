#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+110;
bool ok = true;
int V,E,vi[N];
vector<int> vec[N];

bool dfs(int u, int c){
    if(vi[u])
        return (vi[u] == c);
    vi[u] = c;
    for(int v : vec[u]){
        if(!dfs(v, c == 1 ? 2 : 1))
            return false;
    }
    return true;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    for(int i=1; i<=V; i++){
        if(!vi[i])
            ok &= dfs(i, 1);
    }
    if(ok){
        for(int i=1; i<=V; i++){
            cout << vi[i] << " ";
        }
    }else{
        cout << "IMPOSSIBLE";
    }
}
