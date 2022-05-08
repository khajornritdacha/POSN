#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
int V,E,ti,cas;
vector<int> disc,low;
vector<vector<pi>> vec;
vector<pi> bridge;
///https://www.spoj.com/problems/EC_P/
void dfs(int u, int p){
    disc[u] = low[u] = ++ti;
    for(auto [v, idx] : vec[u]){
        if(idx == p) continue;
        if(disc[v]){
            low[u] = min(low[u], disc[v]);
        }else{
            dfs(v, idx);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]){
                bridge.emplace_back(min(u, v), max(u, v));
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        bridge.clear(); vec.clear(); disc.clear(); low.clear();
        cin >> V >> E;
        if(V == 0 and E == 0)
            break;
        ti = 0;
        vec.resize(V+1); disc.resize(V+1, 0); low.resize(V+1, 0);
        for(int i=1; i<=E; i++){
            int u,v;
            cin >> u >> v;
            vec[u].emplace_back(v, i);
            vec[v].emplace_back(u, i);
        }
        dfs(1, -1);
        sort(bridge.begin(), bridge.end());
        cout << "Caso #" << ++cas << "\n";
        if(bridge.size() == 0){ cout << "Sin bloqueos\n"; continue;}
        cout << bridge.size() << "\n";
        for(auto [u, v] : bridge)
            cout << u << " " << v << "\n";
    }
}

