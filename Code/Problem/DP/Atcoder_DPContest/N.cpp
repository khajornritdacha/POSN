#include <bits/stdc++.h>
using namespace std;

const int N = 410;
using lb = long double;
using ll = long long;

int n,a[N];
ll qs[N],dp[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = 1e18;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
        dp[i][i] = 0;
    }
    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j++){
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+qs[j]-qs[i-1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
