#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 410;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int dp[N][N],qs[N],n,K,a[N];
///http://www.usaco.org/index.php?page=viewproblem2&cpid=945
///dp(i, k) = min( dp(l-1, k-1)+ [ (i-l+1)*max(l...i)-sum(l...i) ] ); 1<=l<=i
///dp(0, 0) = 0
main(){
    ios_base::sync_with_stdio(0); cin.tie(0); freopen("snakes.in", "r", stdin); freopen("snakes.out", "w", stdout);
    cin >> n >> K;
    K++;
    for(int i=0; i<=n; i++) for(int k=0; k<=K; k++) dp[i][k] = 1e9;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
    }
    dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int k=1; k<=K; k++){
            int mx = 0;
            for(int l=i; l>=1; l--){
                mx = max(mx, a[l]);
                dp[i][k] = min(dp[i][k], dp[l-1][k-1]+(i-l+1)*mx-qs[i]+qs[l-1]);
            }
        }
    }

    if(DEBUG){
        cout << "--------------------\n";
        for(int i=1; i<=n; i++){
            cout << "I : " << i << " = ";
            for(int k=1; k<=K; k++){
                cout << dp[i][k] << " ";
            }
            cout << "\n";
        }
        cout << "--------------------\n";
    }
    int ans = 1e9;
    for(int i=1; i<=K; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << "\n";
}
