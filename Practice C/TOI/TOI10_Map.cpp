#include<bits/stdc++.h>
using namespace std;
const int N = 2e2+100;
int pr[]={0,0,-1,1}, pc[]={-1,1,0,0}, m,n,ans[N][N],mr,mc;
vector<int> vec[N*N][4];
void dfs(int u, int p, int code, int nr, int nc){
    if(code == 0){
        mr = min(mr, nr);
        mc = min(mc, nc);
    }else{
        ans[nr][nc] = u;
    }
    for(int i=0; i<4; i++){
        for(int v : vec[u][i]){
            if(v == p) continue;
            dfs(v, u, code, nr+pr[i], nc+pc[i]);
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=1; i<m*n; i++){
        int u,v;
        char c;
        cin >> v >> c >> u;
        u++, v++;
        if(c == 'L'){
            vec[u][0].emplace_back(v);
            vec[v][1].emplace_back(u);
        }else{
            vec[u][2].emplace_back(v);
            vec[v][3].emplace_back(u);
        }
    }
    dfs(1, -1, 0, 0, 0);
    //cout << mr << " " << mc << "\n";
    dfs(1, -1, 1, 1-mr, 1-mc);
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout << ans[i][j]-1 << " \n"[j==n];
        }
    }
}
