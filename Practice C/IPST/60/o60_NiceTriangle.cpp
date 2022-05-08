#include <bits/stdc++.h>
#define DEBUG true
using namespace std;

const int N = 710;
int mod = 29947, X, Y, Z, dp[N][N], lim = 700;

int main(void){
    cin >> X >> Y >> Z;
    X--, Y--, Z--;

    for(int i = 0; i <= lim; i++) dp[i][0] = dp[0][i] = 1;
    for(int i = 1; i <= lim; i++){
        for(int j = 1; j <= lim; j++){
            dp[i][j] = (dp[i][j-1]+dp[i-1][j])%mod;
        }
    }

    int ans = dp[X+Z][Y];
    for(int i = 1; i <= X; i++){
        for(int j = 1; j <= Z; j++){
            ans += dp[i-1][j-1]*dp[X-i+Z-j][Y]; ///choose pair (i, j) and the triangle will be spilt into 2
            ans %= mod;
        }
    }

    cout << ans << "\n";
    return 0;
}
