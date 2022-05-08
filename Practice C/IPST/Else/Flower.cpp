//Task : IPST Oct Flower
//dp(i, j, M, b, c) := the maximum beauty for prefix of type 0 from 1 to i and prefix of type 1 from 1 to j, which has spent money M unit
//b is the current type and c is the number of consecutive flowers of the same type

#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9+10;

int M, K, sz[2], w[2][N], v[2][N], dp[2][N][N][2][3];

int main(void){
    cin >> M >> K;
    for(int i = 1; i <= K; i++){
        int wei, val, cd; cin >> wei >> val >> cd;
        sz[cd]++;
        w[cd][sz[cd]] = wei;
        v[cd][sz[cd]] = val;
    }

    for(int i = 0; i <= 1; i++) for(int j = 0; j <= sz[0]; j++) for(int m = 1; m <= M; m++) for(int b : {0, 1}) for(int c = 1; c <= 2; c++) dp[i][j][m][b][c] = -INF;

    for(int i = 0; i <= sz[0]; i++){
        int cur = i&1;
        for(int j = 0; j <= sz[1]; j++){
            for(int m = 0; m <= M; m++){

                for(int b : {0, 1}){
                    for(int c : {1, 2}){
                        dp[cur][j][m][b][c] = -INF;
                        if(i-1 >= 0)
                            dp[cur][j][m][b][c] = max(dp[cur][j][m][b][c], dp[1-cur][j][m][b][c]);
                        if(j-1 >= 0)
                            dp[cur][j][m][b][c] = max(dp[cur][j][m][b][c], dp[cur][j-1][m][b][c]);
                    }
                }

                if(i-1 >= 0 and m-w[0][i] >= 0){
                    dp[cur][j][m][0][1] = max({dp[cur][j][m][0][1], dp[1-cur][j][m-w[0][i]][0][0] + v[0][i], dp[1-cur][j][m-w[0][i]][1][2] + v[0][i], dp[1-cur][j][m-w[0][i]][1][1] + v[0][i]});
                    dp[cur][j][m][0][2] = max(dp[cur][j][m][0][2], dp[1-cur][j][m-w[0][i]][0][1] + v[0][i]);
                }

                if(j-1 >= 0 and m-w[1][j] >= 0){
                    dp[cur][j][m][1][1] = max({dp[cur][j][m][1][1], dp[cur][j-1][m-w[1][j]][1][0] + v[1][j], dp[cur][j-1][m-w[1][j]][0][2] + v[1][j], dp[cur][j-1][m-w[1][j]][0][1] + v[1][j]});
                    dp[cur][j][m][1][2] = max(dp[cur][j][m][1][2], dp[cur][j-1][m-w[1][j]][1][1] + v[1][j]);
                }

                // cout << "J&M : "<< j << " " << m << " = " << dp[i][j][m][1][1] << " " << dp[i][j][m][1][2] << "\n";
            }
        }
    }

    int ans = 0;

    for(int m = 0; m <= M; m++) for(int b : {0, 1}) for(int c : {1, 2}) ans = max(ans, dp[sz[0]&1][sz[1]][m][b][c]);

    cout << ans << "\n";

    return 0;
}