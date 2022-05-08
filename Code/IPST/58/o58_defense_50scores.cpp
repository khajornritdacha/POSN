#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 6e3+10;
int n,K,dp[N][N],a[N],ans = 1e9;
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
    }
    for(int x=n; x>=1; x--){
        for(int y=x+1; y-x<K; y++){
            for(int z=y+(n-x>=K); z-y<K and z<=n; z++){
                dp[x][y] = min(dp[x][y], dp[y][z]+a[x]);
            }
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
