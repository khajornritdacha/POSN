// Detect cycle in directed graph
#include<bits/stdc++.h>
using namespace std;
int V,E,color[1010];
vector<int> vec[1010];

bool dfs(int u){
    if(color[u]==2)
        return false;
    if(color[u]==1)
        return true;
    color[u]=1;
    for(auto v:vec[u]){
        if(dfs(v))
            return true;
    }
    color[u]=2;
    return false;
}
int main(void){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
    }
    for(int i=1; i<=V; i++){
        if(dfs(i)==1){
            cout << "cycle found\n";
            return 0;
        }
    }
    cout << "no cycle\n";
    return 0;
}
