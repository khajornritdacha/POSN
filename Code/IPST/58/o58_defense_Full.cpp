#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 6e3+10;
int n,K,dp[N][N],a[N],ans = 1e9,mn[N];
///define dp(x,y) = min( dp(y, z) ) + a[x] ; x+1 <= y <= n < x+K and y+(n-x>=K ? 1 : 0) <= z <= n < y+K
///base case dp(x,x) = a[x] O(n^3)
///define mn(x) = min( dp(x, y) ) ; x+y+(n-x>=K-1 ? 1 : 0) <= y <=n < x+K
///new recurrence -> dp(x,y) = mn(y) + a[x] ; x+1 <= y <=n < x+K
///ans = dp(x, y) ; 1 <= x < K and x+1 <= y <= K
main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = 1e9;
            if(i == j)
                dp[i][j] = a[i];
        }
        mn[i] = 1e9;
    }
    for(int x=n; x>=1; x--){
        for(int y=x+1; y-x<K and y<=n; y++){
            dp[x][y] = mn[y]+a[x];
        }
        for(int y=x+(n-x>=K-1); y-x<K and y<=n; y++){
            mn[x] = min(mn[x], dp[x][y]);
        }
    }
    if(DEBUG){
        cout << "        ";
        for(int i=1; i<=n; i++)
            cout << i << "\t";
        cout << "\n";
        for(int i=1; i<=n; i++){
            cout << "I : " << i << "-> ";
            for(int j=1; j<=n; j++){
                if(dp[i][j] == 1e9)
                    dp[i][j] = -1;
                cout << dp[i][j] << "\t\n"[j==n];
            }
        }
    }
    for(int x=1; x<K; x++){
        for(int y=x+1; y-x<K and y<=K; y++){
            ans = min(ans, dp[x][y]);
        }
    }
    cout << ans << "\n";
}
