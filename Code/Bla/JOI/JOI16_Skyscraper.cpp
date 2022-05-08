#include <bits/stdc++.h>
using namespace std;

const int N = 110;
using ll = long long;

ll dp[N][N][N*10][3],mod = 1000000007;
int n,L,a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){ cout << 1; return 0;}

    sort(a+1, a+n+1);

    dp[1][1][0][0] = 1;
    dp[1][1][0][1] = 2;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 0; k <= L; k++){
                for(int l = 0; l <= 2; l++){
                    int nk = 0; ///New total cost
                    if(l < 2){ ///add end point
                        nk = k+((j)*2-l)*abs(a[i+1]-a[i]);
                        if(nk <= L){ ///create new component at end point
                            dp[i+1][j+1][nk][l+1] += dp[i][j][k][l]*(2-l);
                            dp[i+1][j+1][nk][l+1] %= mod;
                        }

                        nk = k+(j*2-l)*abs(a[i+1]-a[i]); ///append i+1th from previous block where i+1th also is end point
                        if(nk <= L){
                            dp[i+1][j][nk][l+1] += dp[i][j][k][l]*(2-l);
                            dp[i+1][j][nk][l+1] %= mod;
                        }

                        /*nk = k+((j-1)*2-l-1)*abs(a[i+1]-a[i]); ///merge ? Never happen bro!
                        if(nk <= L){
                            dp[i+1][j-1][nk][l+1] += dp[i][j][k][l]*(2-l);
                            dp[i+1][j-1][nk][l+1] %= mod;
                        }*/
                    }

                    nk = k+((j)*2-l)*abs(a[i+1]-a[i]); ///create new component
                    if(nk <= L){
                        dp[i+1][j+1][nk][l] += dp[i][j][k][l]*(j+1-l);
                        dp[i+1][j+1][nk][l] %= mod;
                    }

                    nk = k+(j*2-l)*abs(a[i+1]-a[i]); ///append to right most or left most of existing component
                    if(nk <= L){
                        dp[i+1][j][nk][l] += dp[i][j][k][l]*(2*j-l);
                        dp[i+1][j][nk][l] %= mod;
                    }

                    nk = k+((j)*2-l)*abs(a[i+1]-a[i]); ///merge component with i+1th
                    if(nk <= L){
                        dp[i+1][j-1][nk][l] += dp[i][j][k][l]*(j-1);
                        dp[i+1][j-1][nk][l] %= mod;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i <= L; i++) ans = (ans+dp[n][1][i][2])%mod;
    cout << ans << "\n";

    /*for(int i = 1; i <= n; i++){
        cout << "I " << i << "\n";
        for(int j = 1; j <= i; j++){
            cout << "CMP : " << j << "\n";
            for(int k = 0; k <= L; k++){
                cout << "SUM " << k << " : ";
                for(int l = 0; l <= 2; l++){
                    cout << dp[i][j][k][l] << " ";
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }*/

    return 0;
}
