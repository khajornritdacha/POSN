#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1510;
using ll = long long;

int R,C,a[N][N];
ll dp[4][N][N];

///The intersect path is either 1*sz or sz*1
///ans = min( dpTopLeft + dpBotLeft + sum + dpTopRight + dpBotRight )

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=1; i<=R; i++) for(int j=1; j<=C; j++) cin >> a[i][j];
    for(int i=0; i<=R+1; i++) for(int j=0; j<=C+1; j++) for(int t=0; t<4; t++) dp[t][i][j] = 1e18;
    dp[0][0][1] = dp[0][1][0] = 0;
    dp[1][R+1][1] = dp[1][R][0] = 0;
    dp[2][0][C] = dp[2][1][C+1] = 0;
    dp[3][R+1][C] = dp[3][R][C+1] = 0;

    for(int i=1; i<=R; i++) for(int j=1; j<=C; j++) dp[0][i][j] = min(dp[0][i-1][j], dp[0][i][j-1])+a[i][j];
    for(int i=R; i>=1; i--) for(int j=1; j<=C; j++) dp[1][i][j] = min(dp[1][i+1][j], dp[1][i][j-1])+a[i][j];
    for(int i=1; i<=R; i++) for(int j=C; j>=1; j--) dp[2][i][j] = min(dp[2][i-1][j], dp[2][i][j+1])+a[i][j];
    for(int i=R; i>=1; i--) for(int j=C; j>=1; j--) dp[3][i][j] = min(dp[3][i+1][j], dp[3][i][j+1])+a[i][j];

    if(DEBUG){
        for(int t=0; t<4; t++){
            cout << "----------\n";
            cout << "T : " << t << "\n";
            for(int i=1; i<=R; i++){
                for(int j=1; j<=C; j++){
                    cout << dp[t][i][j] << " ";
                }
                cout << "\n";
            }
            cout << "----------\n";
        }
    }


    ll res = 1e18;

    for(int i=1; i<=R; i++){
        ll mn = 1e18; ///minimum of in+sum if (cur in < pre in) then use (cur in) else use (pre in)
        for(int j=1; j<=C; j++){
            ll tmp = min(dp[0][i-1][j], dp[0][i][j-1]) + min(dp[1][i+1][j], dp[1][i][j-1]);
            mn = min(mn, tmp);
            mn += a[i][j];
            ll nowout = min(dp[2][i-1][j], dp[2][i][j+1]) + min(dp[3][i+1][j], dp[3][i][j+1]);
            res = min(res, mn + nowout);
        }
    }

    for(int j=1; j<=C; j++){
        ll mn = 1e18;
        for(int i=1; i<=R; i++){
            ll tmp = min(dp[0][i-1][j], dp[0][i][j-1]) + min(dp[2][i-1][j], dp[2][i][j+1]);
            mn = min(mn, tmp);
            mn += a[i][j];
            ll nowout = min(dp[1][i+1][j], dp[1][i][j-1]) + min(dp[3][i+1][j], dp[3][i][j+1]);
            res = min(res, mn + nowout);
        }
    }

    cout << res << "\n";
}
