#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 310;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,M,K,s[N];
ll p[N][N],dp[N][N];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M >> K;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> p[i][j];
        }
    }
    for(int i = 1 ; i <= M; i++) cin >> s[i];

    for(int i = 0; i <= M+1; i++) for(int k = 0; k <= K; k++) dp[i][k] = INF;
    dp[0][0] = 0;

    for(int i = 1; i <= M+1; i++){
        for(int k = 0; k <= K and k < i; k++){
            for(int j = 1; i-j >= 0 and k-j+1 >= 0; j++){
                dp[i][k] = min(dp[i][k], dp[i-j][k-j+1] + p[s[i-j]][s[i]]);
            }
        }
    }


    ll mn = INF;
    for(int k = 0; k <= K; k++) mn = min(mn, dp[M+1][k]); //we can skip last one
    cout << mn << "\n";
    return 0;
}
