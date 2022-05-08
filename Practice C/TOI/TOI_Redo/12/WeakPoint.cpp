#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

int mx = -1, ans, low[N], id[N], n, K, ti, sz[N];
vector<int> G[N];

void dfs(int u, int p){
    low[u] = id[u] = ++ti;
    int node = 0;
    for(int v : G[u]){
        if(!id[v]){
            dfs(v, u);
            sz[u] += sz[v]+1;
            low[u] = min(low[u], low[v]);

            if(low[v] >= id[u]){ ///the lowest id that v can reach is greater or equal to u then current node is an articulation point
                node += sz[v]+1; ///or else there will exist another path from v to u
            }

        }else{
            low[u] = min(low[u], id[v]);
        }

    }

    if(p == -1) return;

    //cout << u << " " << node << "\n";
    if(node > mx){
        mx = node;
        ans = u;
    }else if(node == mx){
        ans = min(ans, u);
    }

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(K, -1);

    /*for(int i = 1; i <= n; i++){
        cout << "I " << i << " = " << low[i] << " " << id[i] << " " << sz[i] << "\n";
    }*/

    cout << ans << "\n" << mx << "\n";
    return 0;
}

/*
17 10
1 2
2 3
3 1
1 8
8 9
8 10
10 11
2 4
4 5
4 7
5 6
3 12
12 13
12 14
12 15
15 16
16 17
*/
