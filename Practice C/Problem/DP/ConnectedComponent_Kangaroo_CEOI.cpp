#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e3+10;

int n,St,Ed;
ll dp[N][N],mod = 1e9+7;

///https://oj.uz/problem/view/CEOI16_kangaroo
///Always maintain every component to be like this : less more less more less ... more less (less is always at 2 ends)

int main(void){
    cin >> n >> St >> Ed;
    dp[1][1] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            if(i + 1 == St or i + 1 == Ed){
                dp[i+1][j] += dp[i][j]; ///Concatenate endpoint (only 1 way)
                dp[i+1][j] %= mod;
                dp[i+1][j+1] += dp[i][j]; ///Create new component with endpoint
                dp[i+1][j+1] %= mod;
            }else{
                dp[i+1][j-1] += dp[i][j]*(j-1); ///Merge
                dp[i+1][j-1] %= mod;
                dp[i+1][j+1] += dp[i][j]*(j+1-(i >= St)-(i >= Ed)); ///Create new component
                dp[i+1][j+1] %= mod;
            }
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}
