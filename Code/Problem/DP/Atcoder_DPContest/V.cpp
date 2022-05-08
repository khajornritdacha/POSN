#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

int n;
vector<int> G[N];
ll down[N],up[N],mod;

///Down[i] = the number of black and all white from subtree with root i
///Up[i] = the number of ways to color the tree if we remove node i's subtree
///Use prefix and suffix instead of divide operation

ll mul(ll A, ll B){
    return (A*B)%mod;
}

void dfs1(int u, int p){
    down[u] = 1, up[u] = 1;
    for(int v : G[u]){
        if(v == p) continue;
        dfs1(v, u);
        down[u] = mul(down[u], down[v]);
    }
    down[u]++;
}

void dfs2(int u, int p){
    {
        ll pre = up[u]; ///Prefix
        for(int v : G[u]){ if(v == p) continue;
            up[v] = mul(up[v], pre);
            pre = mul(pre, down[v]);
        }
    }
    {
        ll pre = 1; ///Suffix
        for(int i = (int)G[u].size()-1; i >= 0; i--){ int v = G[u][i]; if(v == p) continue;
            up[v] = mul(up[v], pre);
            pre = mul(pre, down[v]);
        }
    }
    {
        for(int v : G[u]){ if(v == p) continue;
            up[v]++;
            dfs2(v, u);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> mod;
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for(int i = 1; i <= n; i++){
        cout << ((down[i]-1)*up[i])%mod << "\n";
    }
    return 0;
}
