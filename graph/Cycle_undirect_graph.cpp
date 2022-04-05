// Detect Cycle in an undirected graph
#include<bits/stdc++.h>
using namespace std;
int V,E,visit[1010];
vector<int> vec[1010];

bool dfs(int u, int p){
    if(visit[u])
        return true;
    visit[u]=true;
    for(auto v:vec[u]){
        if(v!=p&&dfs(v,u))
            return true;
    }
    return false;
}
int main(void){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    for(int i=1; i<=V; i++){
        if(!visit[i]&&dfs(i,0)){
            cout << "cycle found\n";
            return 0;
        }
    }
    cout << "no cycle\n";
    return 0;
}
