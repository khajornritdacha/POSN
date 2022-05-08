#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

///https://beta.programming.in.th/tasks/o59_mar_c1_minturnrun

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R, C, st; cin >> R >> C >> st;
    int pr[] = {0, -1, 1}, pc[] = {-1, 0, 0};
    vector<vector<char>> ta(R+5, vector<char>(C+5));
    vector<vector<vector<int>>> dp(R+5, vector<vector<int>>(C+5, vector<int>(3, INF)));
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> ta[i][j];
        }
    }

    dp[st][0][0] = 0;

    for(int c = 1; c <= C; c++){
        for(int r = 1; r <= R; r++){
            for(int k = 0; k < 3; k++){
                if(ta[r][c] == '#') continue;
                for(int l = 0; l < 3; l++){
                    dp[r][c][k] = min(dp[r][c][k], dp[r+pr[l]][c+pc[l]][l] + (k != l));
                }
            }
        }

        for(int r = R; r >= 1; r--){
            for(int k = 0; k < 3; k++){
                if(ta[r][c] == '#') continue;
                for(int l = 0; l < 3; l++){
                    dp[r][c][k] = min(dp[r][c][k], dp[r+pr[l]][c+pc[l]][l] + (k != l));
                }
            }
        }
    }

    int ans = INF;
    for(int r = 1; r <= R; r++) ans = min({ans, dp[r][C][0], dp[r][C][1], dp[r][C][2]});
    if(ans >= INF) ans = -1;
    cout << ans << "\n";

    return 0;
}
