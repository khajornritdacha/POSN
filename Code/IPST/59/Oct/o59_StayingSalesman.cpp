#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int dp[N][5][8],n,mod=1e9+7,pa[5];
vector<int> go[3];
bool vi[N][5][8];
int solve(int i, int j, int b){
    if(i == 1)
        return (b==7);
    if(vi[i][j][b])
        return dp[i][j][b];
    vi[i][j][b] = true;
    for(int k=1; k<=pa[j] and k<i; k++){
        for(int l : go[j]){
            dp[i][j][b] += solve(i-k, l, b|(1<<l));
            dp[i][j][b] %= mod;
        }
    }
    if(i <= pa[j])
        dp[i][j][b]+=(b==7);
    return dp[i][j][b]%mod;
}
main(){
    cin >> n >> pa[0] >> pa[1] >> pa[2];
    go[0].emplace_back(1);
    go[0].emplace_back(2);
    go[1].emplace_back(2);
    go[2].emplace_back(0);
    cout << solve(n, 0, 1);
}
