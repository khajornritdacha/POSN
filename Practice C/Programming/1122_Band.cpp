#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010;

int n,m,G[N][N];

main(){
    cin >> n >> m;
    vector<pair<int,int>> edge;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        edge.emplace_back(u, v);
        G[u][v] = G[v][u] = i;
    }

    long long ans = 0, dup = 0;
    for(int i = 0; i < m; i++){
        auto [a, b] = edge[i];
        for(int j = 0; j < m; j++){
            auto [c, d] = edge[j];
            if(a == c or a == d or b == c or b == d) continue;
            if(G[a][c] and G[a][d] and G[b][c] and G[b][d]){
                //cout << a << " " << b << " : " << c << " " << d << "\n";
                dup++; ///count pair of fours which has exactly 6 edges
            }
        }
    }

    //cout << dup << "\n";
    dup /= 6;

    for(int e = 0; e < m; e++){
        auto [i, j] = edge[e];
        if(!G[i][j]) continue;
        int cnt = 0;
        for(int k = 1; k <= n; k++){
            if(k == i or k == j) continue;
            cnt += (G[i][k] and G[j][k]);
        }
        ans += 1ll*cnt*(cnt-1)/2; ///count 6 edges case for 6 times
    }


    //cout << ans << "\n";
    cout << ans-dup*5 << "\n";
    return 0;
}
