#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2010;


ll INF = 1e18;
ll n,a[N],dp[N][N];

//https://codeforces.com/problemset/problem/1509/C

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dp[i][j] = INF;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i][i] = 0;
    }

    sort(a+1, a+n+1);

    for(int i = n; i >= 1; i--){
        for(int j = i+1; j <= n; j++){
            dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + a[j]-a[i];
        }
    }

    cout << dp[1][n] << "\n";



    return 0;
}