#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
int n,mx,m;
bool vi[N],cycle;
vector<int> vec[N];

void dfs(int u, int p=-1){
    if(vi[u]){
        cycle = true;
        return;
    }
    vi[u] = true;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
    }
}
main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
        mx = max(u, v);
    }
    for(int i=1; i<=n; i++){
        if(!vi[i])
            dfs(i);
    }

    if(cycle)
        cout << "Y";
    else
        cout << "N";
}
