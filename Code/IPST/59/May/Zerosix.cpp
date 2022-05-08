#include <bits/stdc++.h>
using namespace std;

const int N = 110, lim = 3010, INF = 1e9;
int R,C,dp[N][N][lim];
bool vi[N][N][lim];

struct DATA{
    int se, th;
} a[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            int x; cin >> x;
            while(x%2 == 0) a[i][j].se++, x /= 2;
            while(x%3 == 0) a[i][j].th++, x /= 3; 
        }
    }

    vi[1][1][a[1][1].th] = true;
    dp[1][1][a[1][1].th] = a[1][1].se;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            for(int k = a[i][j].th; k < lim; k++){
                if(vi[i-1][j][k-a[i][j].th]){
                    vi[i][j][k] = true;
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-a[i][j].th] + a[i][j].se);
                }
                if(vi[i][j-1][k-a[i][j].th]){
                    vi[i][j][k] = true;
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-a[i][j].th] + a[i][j].se);
                }
            }
        }
    }

    int ans = 0;
    for(int k = 0; k < lim; k++) if(vi[R][C][k]) ans = max(ans, min(k, dp[R][C][k]));
    cout << ans << "\n";

    return 0;
}