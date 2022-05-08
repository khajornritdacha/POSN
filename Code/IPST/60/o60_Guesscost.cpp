#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int n,a[N],dp[N][N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        for(int j=i; j<=n; j++){
            dp[i][j] = 1e9;
        }
        dp[i][i] = a[i];
    }

    for(int i=n; i>=1; i--){
        for(int j=i+1; j<=n; j++){
            for(int k=i; k<=j; k++){
                dp[i][j] = min(dp[i][j], max(dp[i][k-1], dp[k+1][j])+a[k]);
            }
        }
    }

    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << dp[1][n];
}
