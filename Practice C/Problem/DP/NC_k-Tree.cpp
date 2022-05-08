#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,K,D,dp[N][2],mod=1e9+7;
bool vi[N][2];
int solve(int i, bool b){
    if(i==0)
        return b;
    if(vi[i][b])
        return dp[i][b];
    vi[i][b] = true;
    for(int j=1; j<=i and j<=K; j++){
        dp[i][b] += solve(i-j, b|(j>=D))%mod;
        dp[i][b] %= mod;
    }
    return dp[i][b]%mod;
}
void test_case(){
    cin >> n >> K >> D;
    cout << solve(n, 0);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        test_case();
    }
}
///https://codeforces.com/problemset/problem/431/C
