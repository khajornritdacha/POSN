#include <bits/stdc++.h>
using namespace std;

const int N = 210;

int n,m;
bool ban[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        ban[u][v] = true;
    }  

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                ans += !(ban[i][j] or ban[i][k] or ban[j][k]);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}