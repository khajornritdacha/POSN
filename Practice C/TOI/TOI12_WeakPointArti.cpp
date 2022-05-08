#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 5e5+1;
int n,st,mx=-1,node,low[N],disc[N],ti,ch[N];
vector<int> vec[N];

void dfs(int u, int p){
    int res = 0;
    ch[u] = 1;
    low[u] = disc[u] = ti++;
    for(int v : vec[u]){
        if(v == p) continue;
        if(disc[v] != -1){
            low[u] = min(low[u], disc[v]);
        }else{
            dfs(v, u);
            ch[u] += ch[v];
            low[u] = min(low[u], low[v]);
            if(low[v] >= disc[u]){
                res += ch[v];
            }
        }
    }
    if(p == -1) return;
    if(res > mx){
        mx = res, node = u;
    }else if(res == mx){
        node = min(node, u);
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> st;
    for(int i=1; i<=n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    memset(disc, -1, sizeof(disc));
    dfs(st, -1);

    cout << node << "\n" << mx;
}
