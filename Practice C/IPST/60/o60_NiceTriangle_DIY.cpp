#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 360;
int mod = 29947, X, Y, Z, dp[N][N], dp2[N][2*N];

///2 sets of a pair of lines

int main(void){
    cin >> X >> Y >> Z;
    X--, Y--, Z--;
    for(int i = 0; i <= Z; i++){
        for(int j = 0; j <= Y; j++){
            if(i == 0 or j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i][j-1]+dp[i-1][j])%mod;
            if(i == Z or j == 0)
                dp2[0][i+j] = dp[i][j];
        }
    }

    for(int i = 1; i <= X; i++){
        for(int j = 0; j <= Y+Z; j++){
            if(j == 0){
                dp2[i][j] = 1; continue;
            }
            dp2[i][j] = dp2[i-1][j];
            for(int k = 1; k <= j; k++){
                if(j <= Z){
                    dp2[i][j] += dp2[i-1][k-1]*dp[j-k][0];
                }else{
                    if(k <= Z)
                        dp2[i][j] += dp2[i-1][k-1]*dp[Z-k][j-Z];
                    else
                        dp2[i][j] += dp2[i-1][k-1]*dp[0][Y-k+Z];
                }
                if(dp2[i][j] >= mod*mod){
                    dp2[i][j] -= mod*mod;
                }
            }
            dp2[i][j] %= mod;
        }
    }

    if(DEBUG){
        cout << "-------------------\n";
        for(int i = 0; i <= Z; i++){
            for(int j = 0; j <= Y; j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-------------------\n";
        for(int i = 0; i <= X; i++){
            for(int j = 0; j <= Y+Z; j++){
                cout << dp2[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-------------------\n";
    }

    cout << dp2[X][Y+Z];
    return 0;
}
