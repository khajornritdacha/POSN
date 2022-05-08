#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using ll = long long;
const int N = 1e5+100;
int a[N],dp[N][5],n,P;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> P;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=0; i<=n; i++)
        dp[i][0] = dp[i][1] = dp[i][2] = 2e9;
    dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int k=0; k<=2 and i-1>=k; k++){
            for(int j=0; j<=k and i-j-1 >= 0; j++){
                dp[i][k] = min(dp[i][k], dp[i-j-1][k-j]+(a[i]-a[i-j-1])*(((i-k)%2) ? -1 : 1));
            }
        }
    }
    if(dp[n][2] == 2e9)
        cout << P*-1;
    else
        cout << dp[n][2]+(P-a[n])*(((n-2)%2) ? 1 : -1);
}
///https://www.proprog.ml/tasks/aircon/descs/7297
