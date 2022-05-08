#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 5010;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;
using ll = long long;

int dp[N][N],n,m,a[N],b[N];
///https://codeforces.com/problemset/problem/1525/D
///dp(i, j) = ith person with jth chair
///dp(i, j) = min( dp(i, j-1), dp(i-1, j-1) ); i<=j
void test_case(){
    int tmp = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x)
            a[++tmp] = i;
        else
            b[++m] = i;
    }
    n = tmp;
    int ans = 1e9;
    for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) dp[i][j] = 1e9;
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=m; j++){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]+abs(a[i]-b[j]));
        }
    }
    ans = dp[n][m];
    if(n == 0) ans = 0;
    cout << ans << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
        test_case();
    }
}
