#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n,a[N],dp[N][2];
///https://codeforces.com/problemset/problem/1418/C

void test_case(){
    cin >> n;
    dp[0][0] = 1e9, dp[0][1] == 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i][0] = dp[i][1] = 1e9;
    }

    for(int i=1; i<=n; i++){
        dp[i][0] = dp[i-1][1]+a[i];
        if(i >= 2){
            dp[i][0] = min(dp[i][0], dp[i-2][1]+a[i]+a[i-1]);
            dp[i][1] = dp[i-1][0];
        }
        if(i >= 3){
            dp[i][1] = min(dp[i][1], dp[i-2][0]);
        }
    }

    cout << min(dp[n][0], dp[n][1]) << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
