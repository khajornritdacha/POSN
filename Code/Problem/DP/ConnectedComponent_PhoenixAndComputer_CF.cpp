#include <bits/stdc++.h>
using namespace std;

const int N = 410;
using ll = long long;
int n;
ll M,dp[N][N];

///Dp(i, j) := the number of ways that a sequence of n bits has i bits of 1 with j component
///https://codeforces.com/contest/1515/problem/E
///https://codeforces.com/blog/entry/92602?f0a28=2&fbclid=IwAR1ibRza-0jByuLQPy0BSHtQrF3u2aA9p7AUxlzYS1V6TQSMAm0avo7sROY#comment-813541

void add(ll &A, ll B){ A = (A+B)%M; return;}

int main(void){
    cin >> n >> M;
    dp[1][1] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            add(dp[i+1][j], dp[i][j]*2ll*j);

            add(dp[i+2][j], dp[i][j]*2ll*j);

            add(dp[i+1][j+1], dp[i][j]*(j+1));

            add(dp[i+2][j-1], dp[i][j]*2ll*(j-1));

            add(dp[i+3][j-1], dp[i][j]*(j-1));
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}
