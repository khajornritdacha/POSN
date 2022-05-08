#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10, INF = 2e9;
using ll = long long;
using pi = pair<int, int>;

int mx = -1, node, n, S, ti, low[N], id[N], sz[N];
vector<int> G[N];

void dfs(int u, int p){
    int arti = 0;
    low[u] = id[u] = ++ti;
    for(int v : G[u]){
        if(!id[v]){
            dfs(v, u);

            sz[u] += sz[v] + 1;
            low[u] = min(low[u], low[v]);

            if(low[v] >= id[u]){ //the minimum id that v can go is greater or equal than u imply that v can't go to any node higher than u
                arti += sz[v]+1;  //then u is articulation point
            }
    
        }else{
            low[u] = min(low[u], id[v]); //back edge
        }
    }

    if(u != S){
        //cout << "ARTI : " << u << " " << arti << "\n";
        if(arti > mx){
            mx = arti;
            node = u;
        }else if(arti == mx){
            node = min(node, u);
        }
    }
}

int main(void){
    cin >> n >> S;
    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(S, -1);

    cout << node << "\n" << mx << "\n";
    return 0;
}