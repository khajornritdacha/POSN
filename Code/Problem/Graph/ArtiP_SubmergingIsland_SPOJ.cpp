#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
int V,E,ti;
set<int> arti;
vector<int> disc,low;
vector<vector<int>> vec;
///https://www.spoj.com/problems/SUBMERGE/
void dfs(int u, int p){
    disc[u] = low[u] = ++ti;
    int ch = 0;
    for(int v : vec[u]){
        if(v == p) continue;
        if(disc[v]){
            low[u] = min(low[u], disc[v]);
        }else{
            ch++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(u != 1 and low[v] >= disc[u]){
                arti.insert(u);
            }
        }
    }
    if(u == 1 and ch > 1)
        arti.insert(u);
    //cout << u << " " << disc[u] << " " << low[u] << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        arti.clear(); vec.clear(); disc.clear(); low.clear();
        cin >> V >> E;
        if(V == 0 and E == 0)
            break;
        ti = 0;
        vec.resize(V+1); disc.resize(V+1, 0); low.resize(V+1, 0);
        for(int i=1; i<=E; i++){
            int u,v;
            cin >> u >> v;
            vec[u].emplace_back(v);
            vec[v].emplace_back(u);
        }
        dfs(1, -1);
        cout << arti.size() << "\n";
    }
}

