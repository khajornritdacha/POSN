#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int ans,a[N][N],now[N],n,m;
void solve(int lv = 1){
    if(lv == m+1){
        int cnt = 0;
        for(int i=1; i<=n; i++){
            bool lie = false;
            for(int j=1; j<=m; j++){
                if(a[i][j] == 0) continue;
                if(a[i][j] != now[j])
                    lie = true;
            }
            cnt += lie;
        }
        ans = min(ans, cnt);
        return;
    }
    now[lv]=-1;
    solve(lv+1);
    now[lv]=1;
    solve(lv+1);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    ans = n;
    solve();
    cout << ans << "\n";
}
