#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int n;
ll qs[3][N],dp[3][N];

int main(void){
    cin >> n;
    for(int lv = 0; lv < 3; lv++){
        for(int i = 1; i <= n; i++){
            cin >> qs[lv][i];
            qs[lv][i] += qs[lv][i-1];
            dp[0][i] = qs[0][i];
        }
    }

    for(int lv : {1, 2}){
        ll mn = dp[lv-1][lv]-qs[lv][lv];
        for(int i = lv+1; i <= n; i++){
            dp[lv][i] = mn+qs[lv][i];
            mn = min(mn, dp[lv-1][i]-qs[lv][i]);
        }
    }

    cout << dp[2][n] << "\n";
    return 0;
}
