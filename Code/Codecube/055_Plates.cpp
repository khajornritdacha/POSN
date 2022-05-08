#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3+10;
int dp[N][N], mod = 9871;
///dp(i, j) = the number of ans with i plates and j stacks
///dp(i, j) = j*dp(i-1, j)+dp(i-1, j-1) -> j*dp(i-1, j) becuz i-th plate can be put either stack 1, 2, ..., or j. dp(i-1, j-1) becuz i-th plate as a new stack.
///dp(0, 0) = 1
main(){
    dp[0][0] = 1;
    for(int j=1; j<=1e3; j++){
        for(int i=j; i<=1e3; i++){
            dp[i][j] = (j*dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        int n,K;
        cin >> n >> K;
        cout << dp[n][K] << "\n";
    }

}
