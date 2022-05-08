#include<bits/stdc++.h>
using namespace std;

int dp[110][110][110],n,K,mod=2553;
vector<tuple<int,int,int,int>> vec;
bool vi[110][110][110];

int solve(int i, int j, int k){
    if(i == 0 and j == 0 and k == 0)
        return dp[i][j][k] = 1;
    if(i == 0 or j == 0 or k == 0)
        return dp[i][j][k] = 0;
    if(i == 1 or j == 1 or k == 1)
        return dp[i][j][k] = 1;
    if(vi[i][j][k])
        return dp[i][j][k];
    vi[i][j][k] = true;
    int sum = 0;
    for(int m=1; m<=K and m<=i; m++){
        for(int o=1; o<=K and o<=j; o++){
            for(int l=1; l<=K and l<=k; l++){
                sum += solve(i-m, j-o, k-l)%mod;
                sum %= mod;
            }
        }
    }
    return dp[i][j][k] = sum;
}

main(){
    cin >> n >> K;
    //cout << K << "\n";
    cout << solve(n,n,n) << "\n";
}
