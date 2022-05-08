#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int R,C,dp[N][N];
char a[N][N];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }    

    for(int i = 0; i <= R; i++) for(int j = 0; j <= C; j++) dp[i][j] = INF;
    dp[1][1] = 1;

    int ar = 0, ac = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){

            if(dp[i-1][j] < INF and (a[i-1][j] == 'B' or a[i-1][j] == 'D')){
                dp[i][j] = dp[i-1][j]+1;
            }
            if(dp[i][j-1] < INF and (a[i][j-1] == 'B' or a[i][j-1] == 'R')){
                if(dp[i][j-1] + 1 == dp[i][j]){
                    if(dp[i][j] < dp[ar][ac]){
                        ar = i, ac = j;
                    }
                } else if(dp[i][j-1] + 1 < dp[i][j]){
                    dp[i][j] = dp[i][j-1] + 1;
                }
            }
        }
    }

    cout << dp[ar][ac] << "\n" << ar << " " << ac << "\n";
    return 0;
}