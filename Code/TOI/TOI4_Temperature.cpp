#include<bits/stdc++.h>
using namespace std;
int ans = -1e9,n,sx,sy,a[30][30],pr[]={-1,1,0,0},pc[]={0,0,-1,1};
void dfs(int r, int c){
    if(a[r][c] == 100) return;
    ans = max(ans, a[r][c]);
    for(int i=0; i<4; i++){
        int nr = r+pr[i], nc = c+pc[i];
        if(nr < 1 or nr > n or nc < 1 or nc > n or a[nr][nc]<=a[r][c]) continue;
        dfs(nr, nc);
    }
}
main(){
    cin >> n >> sx >> sy;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> a[i][j];
    dfs(sy, sx);
    cout << ans;
}
