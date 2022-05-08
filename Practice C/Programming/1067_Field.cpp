#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,m,K,a[N][N],ans[N][N],vi[N][N],pr[]={0,-1,0,1,0},pc[]={0,0,1,0,-1};
string pat[]={"X", "N", "E", "S", "W", "NO"};
int dfs(int r, int c){
    if(r < 1) return 1;
    if(c > m) return 2;
    if(r > n) return 3;
    if(c < 1) return 4;
    if(vi[r][c] == 1) return 5;
    if(vi[r][c] == 2) return ans[r][c];
    vi[r][c] = 1;
    ans[r][c] = dfs(r+pr[a[r][c]], c+pc[a[r][c]]);
    vi[r][c] = 2;
    return ans[r][c];
}
main(){
    cin >> m >> n >> K;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!vi[i][j])
                dfs(i, j);
        }
    }
    for(int i=1; i<=K; i++){
        int x,y;
        cin >> x >> y;
        cout << pat[ans[y][x]] << "\n";
    }
}
