#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m, C, dp[1<<10][N], co[N], mod = 1000003;
vector<int> G[N][10];

void add(int &A, int B){
    A += B;
    if(A >= mod) A-= mod;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> C;
    for(int i = 1; i <= n; i++){
        cin >> co[i];
        dp[1<<co[i]][i] = 1;
    }
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        u++, v++;
        G[u][co[v]].emplace_back(v);
        G[v][co[u]].emplace_back(u);
    }

    for(int bit = 0; bit < 1<<C; bit++){
        vector<int> zero;
        for(int j = 0; j < C; j++){
            if(bit&(1<<j)) continue;
            zero.emplace_back(j);
        }

        for(int i = 1; i <= n; i++){
            if(bit&(1<<co[i]) == 0) continue;
            
            for(int cur : zero){ //little optimization
                int go = bit|(1<<cur);
                for(int v : G[i][cur]){
                    add(dp[go][v], dp[bit][i]);
                }
            }

        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) add(ans, dp[(1<<C)-1][i]);
    cout << ans << "\n";

    return 0;
}