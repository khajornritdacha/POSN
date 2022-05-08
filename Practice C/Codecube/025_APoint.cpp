#include<bits/stdc++.h>
using namespace std;

const int N = 6e3+10;
int n,qs[N],dp[N][N],a[N];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
    }
    for(int i=n; i>=1; i--){
        for(int j=i+1; j<=n; j++){
            for(int k=i; k<j; k++){
                int sum1 = qs[k]-qs[i-1];
                int sum2 = qs[j]-qs[k];
                dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]+2*min(sum1, sum2)+max(sum1, sum2));
            }
        }
    }
    cout << dp[1][n];
}
