#include<bits/stdc++.h>
using namespace std;

int bt[25],V,E,st,ed;
vector<int> vec[25];

void dfs(int u, int p=-1){
    for(int v : vec[u]){
        if(v==p or v == st) continue;
        if(bt[v] != -1) continue;
        bt[v] = u;
        dfs(v, u);
    }
}
main(){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
    }
    cin >> st >> ed;

    for(int i=0; i<V; i++)
        bt[i] = -1;
    dfs(st);

    if(ed != st and bt[ed] == -1)
        cout << "No path exists (" << st << " -> " << ed << ")";
    else{
        cout << "path:";
        int now = ed;
        vector<int> ans;
        while(now != -1){
            //cout << now << "\n";
            ans.emplace_back(now);
            now = bt[now];
        }
        while(!ans.empty()){
            cout << ans.back() << " ";
            ans.pop_back();
        }
    }
}
