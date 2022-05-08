#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

///https://codeforces.com/problemset/problem/1418/C
/// 6 Nov 2021

int n,a[N],dp[N][2];

void test_case(){
    cin >> n;
    for(int i = 2; i <= n+1; i++){
        cin >> a[i];
    }

    dp[1][1] = 0;
    dp[0][0] = dp[0][1] = dp[1][0] = 1e9;
    for(int i = 2; i <= n+1; i++){
        dp[i][0] = min(dp[i-1][1]+a[i], dp[i-2][1]+a[i-1]+a[i]);
        dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
    }
    cout << min(dp[n+1][0], dp[n+1][1]) << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
