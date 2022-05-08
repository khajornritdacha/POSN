#include <bits/stdc++.h>
using namespace std;

const int N = 130;
using ll = long long;
int n,K;
ll C[N],dp[30][N][N],ans[2][N][N];

main(){
    cin >> n >> K;
    for(int i=0; i<(1<<K); i++){
        cin >> C[i];
    }

    if(n == K){
        ll res = 0;
        for(int i=0; i<(1<<K); i++)
            res = max(res, C[i]);
        cout << res << "\n"; return 0;
    }
    n -= K;

    bool cur = 0;
    for(int i=0; i<(1<<K); i++){
        int nx1, nx2;
        nx1 = (i>>1); nx2 = nx1|(1<<(K-1));
        dp[0][nx1][i] = C[nx1]+C[i];
        dp[0][nx2][i] = C[nx2]+C[i];

        if(n&1){
            ans[cur][nx1][i] = dp[0][nx1][i];
            ans[cur][nx2][i] = dp[0][nx2][i];
        }
    }

    cur = !cur;
    n/=2;
    for(int id=1; n; n/=2, id++){
        for(int i=0; i<(1<<K); i++){
            for(int j=0; j<(1<<K); j++){
                for(int k=0; k<(1<<K); k++){
                    dp[id][i][j] = max(dp[id][i][j], dp[id-1][i][k]+dp[id-1][k][j]-C[k]);
                }
            }
        }

        if(n&1){
            for(int i=0; i<(1<<K); i++){
                for(int j=0; j<(1<<K); j++){
                    ans[cur][i][j] = 0;
                    for(int k=0; k<(1<<K); k++){
                        ans[cur][i][j] = max({ans[cur][i][j],
                                             (ans[!cur][i][k] ? ans[!cur][i][k]+dp[id][k][j]-C[k] : dp[id][i][j]),
                                             (ans[!cur][k][j] ? dp[id][i][k]+ans[!cur][k][j]-C[k] : dp[id][i][j])});
                    }
                }
            }
            cur = !cur;
        }
    }

    ll res = 0;
    for(int i=0; i<(1<<K); i++) for(int j=0; j<(1<<K); j++) res = max(res, ans[!cur][i][j]);
    cout << res << "\n";
}
