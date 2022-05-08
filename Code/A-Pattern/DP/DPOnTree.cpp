///Find maximum sum of subset of nodes without choosing the adjacent node
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],V,c[N],gc[N];
vector<int> vec[N];
void dfs(int u, int p){
    for(int v : vec[u]){
        if(v==p) continue;
        dfs(v, u);
        c[u]+=gc[v];
        gc[u]+=max(gc[v], c[v]);
    }
    c[u]+=a[u];
    return;
}
main(){
    cin >> V;
    for(int i=1; i<=V; i++)
        cin >> a[i];
    for(int i=1; i<V; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    dfs(1, -1);
    cout << max(c[1], gc[1]) << "\n";
}
/*
9
1 2 3 4 1 1 10 2 1
1 2
1 3
1 4
2 5
2 6
6 8
6 9
4 7
*/
