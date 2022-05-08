#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e4+10;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int n,K,a[N],dp[N];
///http://www.usaco.org/index.php?page=viewproblem2&cpid=863
///dp(i) = max( dp(j-1)+(i-j+1)*max(j...i) ); i-j+1<=K
main(){
    ios_base::sync_with_stdio(0); cin.tie(0); freopen("teamwork.in", "r", stdin); freopen("teamwork.out", "w", stdout);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        int mx = 0;
        for(int j=i; i-j+1<=K and j>=1; j--){
            mx = max(mx, a[j]);
            dp[i] = max(dp[i], dp[j-1]+(i-j+1)*mx);
        }
    }
    cout << dp[n];
}
