#include<bits/stdc++.h>
using namespace std;
int V,E,color[100100];
vector<int> vec[100100];
bool dfs(int u, int p, int c){
    if(color[u]!=0)
        return color[u]==c;
    color[u]=c;
    for(auto v : vec[u]){
        if(v==p) continue;
        if(!dfs(v,u,c==1 ? 2 : 1))
            return false;
    }
    return true;
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
        if(!color[i]){
            if(!dfs(i,0,1)){
                cout << "Non Bipartite Graph\n";
                return 0;
            }
        }
    }
    cout << "Bipartite Graph\n";
}
