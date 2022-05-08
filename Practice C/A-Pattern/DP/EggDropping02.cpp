#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int K,n,dp[110][N],m;
///define dp(M, K) as the maximum numbers of floors with only M dropping and K eggs
///dp(0, K) = 0
///dp(M, K) = dp(M-1, K-1) + dp(M-1, K) + 1
///dp(M-1, K-1) for the case that egg breaks
///dp(M-1, K) for the case that egg does not break
///1 for the current floor
///use plus(+) sign because if egg breaks we still be able to identify at most dp(M-1, K-1) floors and if egg does not break, a numbers of floors with the optimal dropping will be dp(M-1, K) floors.
///also plus 1 because whether egg breaks or not we still know the result in the current floor, so just plus 1.
///O(Klogn) -> because dp(M, K) is increasing exponentially to n
///Memory can be optimized into O(K)
main(){
    cin >> K >> n;
    while(dp[m][K] < n){
        m++;
        for(int k=1; k<=K; k++)
            dp[m][k] = dp[m-1][k-1]+dp[m-1][k]+1;
    }
    cout << m;
}
