#include <bits/stdc++.h>
using namespace std;

const int N = 210, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int tr[N*N], tc[N*N], mnr = INF, mnc = INF, R, C, n, ans[N][N];
vector<tu> G[N*N];

void dfs(int u, int p, int r, int c){
    tr[u] = r, tc[u] = c;
    mnr = min(mnr, r), mnc = min(mnc, c);

    //cout << u << " " << p << "\n";
    
    for(auto [v, dr, dc] : G[u]){
        if(v == p) continue;

        dfs(v, u, r+dr, c+dc);
    }
}


int main(void){
    cin >> R >> C;
    n = R*C;
    for(int i = 1; i < n; i++){
        int u, v; 
        char c;
        cin >> u >> c >> v;
        u++, v++;

        int dr = 0, dc = 0;
        if(c == 'U') dr = 1;
        else dc = 1;

        G[u].emplace_back(v, dr, dc);
        G[v].emplace_back(u, -dr, -dc);
    }    

    dfs(1, -1, 0, 0);

    for(int i = 1; i <= n; i++){
        //cout << tr[i] << " " << tc[i] << "\n";
        ans[tr[i]-mnr][tc[i]-mnc] = i-1;
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}