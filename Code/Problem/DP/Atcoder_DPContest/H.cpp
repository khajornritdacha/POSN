#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int R,C,dp[N][N],mod = 1e9+7;


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            char c; cin >> c;
            if(c == '.'){
                if(i == 1 and j == 1) dp[1][1] = 1;
                else dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout << dp[R][C] << "\n";
    return 0;
}
