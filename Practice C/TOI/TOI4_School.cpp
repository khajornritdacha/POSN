#include<bits/stdc++.h>
using namespace std;
const int N = 1e2;
int dp[N][N],n,m,mx,mn=1e9,pr[]={-1,1,0,0},pc[]={0,0,-1,1},cnt;
bool vi[N][N];
char a[N][N];
void dfs(int r, int c){
    if(vi[r][c]) return;
    vi[r][c] = true;
    for(int i=0; i<4; i++){
        int nr = r+pr[i], nc = c+pc[i];
        if(nr < 1 or nr > n or nc < 1 or nc > m or a[nr][nc] != 'P') continue;
        dfs(nr, nc);
    }
}
void solve(int r, int c){
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) vi[i][j] = 0;
    cnt = 0;
    for(int i=r; i<r+mx; i++){
        for(int j=c; j<c+mx; j++){
            if(a[i][j] == 'P' and !vi[i][j]){
                cnt++, dfs(i,j);
            }
        }
    }
    mn = min(mn, cnt);
}
main(){
    cin >> m >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=n; i>=1; i--){
        for(int j=m; j>=1; j--){
            if(a[i][j] == 'T') continue;
            dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]})+1;
            mx = max(mx, dp[i][j]);
        }
    }
    if(mx == 0){
        cout << "0 0\n";
        return 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j] == mx){
                solve(i, j);
            }
        }
    }
    cout << mx*mx << " " << mn << "\n";
}
