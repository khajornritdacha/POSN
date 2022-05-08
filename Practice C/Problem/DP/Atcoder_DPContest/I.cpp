#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
using lb = long double;

int n;
lb P[N],dp[N][N];


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> P[i];
    }
    dp[0][0] = 1.0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = dp[i-1][j]*(1-P[i]);
            if(j > 0)
                dp[i][j] += dp[i-1][j-1]*P[i];
        }
    }
    lb ans = 0;
    for(int i = (n+1)/2; i <= n; i++){
        ans += dp[n][i];
    }
    cout << setprecision(10) << fixed << ans << "\n";
    return 0;
}
