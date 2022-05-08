#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int B = 500;

    int n, m, Q; cin >> n >> m >> Q;

    vector<vector<int>> G(m+5), bb(n+5);
    vector<int> lis;
    int cp[m+5] = {}, qq[n+5] = {};


    for(int i = 1; i <= m; i++){
        int sz; cin >> sz;
        if(sz > B) lis.emplace_back(i);

        G[i].resize(sz);
        for(int &v : G[i]){
            cin >> v;
            if(sz > B) bb[v].emplace_back(i);
        }
    }

    while(Q--){
        int t; cin >> t;
        if(t == 1){
             int x, y; cin >> x >> y;
             if(G[x].size() <= B){
                 for(int v : G[x]) qq[v] += y-cp[x];
             }
             cp[x] = y;
        } else if(t == 2){
            int u; cin >> u;
            int res = qq[u];
            for(int v : bb[u]) res += cp[v];
            cout << res << "\n";
        } else {
            assert(0);
        }
    }

    return 0;
}