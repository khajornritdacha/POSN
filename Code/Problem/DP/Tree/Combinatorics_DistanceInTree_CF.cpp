#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
using ll = long long;

int n,K;
ll ch[N][510],ans;
vector<int> G[N];

void dfs(int u, int p){
    ch[u][0] = 1;
    for(int v : G[u]){
        if(v == p) continue;

        dfs(v, u);

        for(int k = 0; K-k-1 >= 0; k++){
            ans += ch[u][k] * ch[v][K-k-1];
        }
        for(int k = 0; k < K; k++){
            ch[u][k+1] += ch[v][k];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n-1; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, -1);

    cout << ans << "\n";
    return 0;
}
