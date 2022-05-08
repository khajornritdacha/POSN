#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int V,E;
vector<int> vec[N],use;
bool vi[N];

void dfs(int u){
    vi[u] = true;
    for(int v : vec[u])
        if(!vi[v])
            dfs(v);
}
main(){
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    for(int i=1; i<=V; i++){
        if(!vi[i]){
            use.emplace_back(i);
            dfs(i);
        }
    }
    cout << (int)use.size()-1 << "\n";
    for(int i=1; i<use.size(); i++)
        cout << use[0] << " " << use[i] << "\n";
}
