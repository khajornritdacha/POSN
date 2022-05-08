#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

using ll = long long;
const int N = 35;

int n;
char a[N][N];
bool dp[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    int ans = 1;
    dp[n][n] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            if(i == n and j == n) continue;
            if(a[i][j] != '.') continue;
            dp[i][j] = dp[i+1][j]|dp[i][j+1];
            ans += dp[i][j];
        }
    }

    cout << ans << "\n";
    return 0;
}
