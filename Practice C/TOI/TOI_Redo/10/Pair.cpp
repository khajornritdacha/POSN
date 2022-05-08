#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,dp[N][N];
char a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int l = n-1; l >= 1; l--){
        for(int r = l+1; r <= n; r++){
            dp[l][r] = max(dp[l][r-1], dp[l+1][r]);
            for(int k = l+1; k <= r; k++){
                if(a[l] == a[k]) 
                    dp[l][r] = max(dp[l][r], dp[l+1][k-1] + dp[k+1][r] + 1); //pair with 
                dp[l][r] = max(dp[l][r], dp[l][k-1] + dp[k+1][r]); //throw away
            }
        }
    }    

    cout << dp[1][n] << "\n";

    return 0;   
}