#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5010;

///https://codeforces.com/contest/704/problem/B

int n,St,Ed;
ll x[N],a[N],b[N],c[N],d[N],dp[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> St >> Ed;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    memset(dp, 64, sizeof(dp));

    //cout << dp[1][1] << "\n";
    if(1 == St)
        dp[1][1] = d[1];
    else if(1 == Ed)
        dp[1][1] = b[1];
    else
        dp[1][1] = b[1]+d[1];

    for(int i = 1; i < n; i++){
        for(int j = 1+(i >= St and i >= Ed and i < n-1); j <= i; j++){ ///If St and Ed are put, j = 1 will not be defined until i = n-1
            ll pus = dp[i][j]+(x[i+1]-x[i])*(2ll*j-(i >= St)-(i >= Ed));
            ll tmp = dp[0][0]; ///set to inf
            if((i < St or j != 1) and i+1 != Ed) ///Concatenate to the left
                tmp = min(tmp, pus+c[i+1]+(i+1 == St ? 0 : b[i+1]));
            if((i < Ed or j != 1) and i+1 != St) ///Concatenate to the right
                tmp = min(tmp, pus+a[i+1]+(i+1 == Ed ? 0 : d[i+1]));
            dp[i+1][j] = min(dp[i+1][j], tmp);

            dp[i+1][j+1] = min(dp[i+1][j+1], pus+(i+1 == St ? 0 : b[i+1])+(i+1 == Ed ? 0 : d[i+1])); ///Create new component

            if(i+1 != St and i+1 != Ed) ///Merge component
                dp[i+1][j-1] = min(dp[i+1][j-1], pus+a[i+1]+c[i+1]);
        }
    }

    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << dp[n][1] << "\n";
    return 0;
}
