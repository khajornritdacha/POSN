#include <bits/stdc++.h>
using namespace std;

const int N = 260;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,a[N];
bool dp[N][N][3];

void test_case(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        a[i] = c-'0';
        dp[i][i][a[i]] = 1;
    }

    for(int l = n-1; l >= 1; l--){
        for(int r = l+1; r <= n; r++){
            for(int k = l; k < r; k++){
                dp[l][r][0] |= dp[l][k][0]&dp[k+1][r][2];

                dp[l][r][1] |= dp[l][k][0]&dp[k+1][r][1];
                dp[l][r][1] |= dp[l][k][1]&dp[k+1][r][1];
                dp[l][r][1] |= dp[l][k][1]&dp[k+1][r][2];
                dp[l][r][1] |= dp[l][k][2]&dp[k+1][r][0];
                dp[l][r][1] |= dp[l][k][2]&dp[k+1][r][2];

                dp[l][r][2] |= dp[l][k][0]&dp[k+1][r][0];
                dp[l][r][2] |= dp[l][k][1]&dp[k+1][r][0];
                dp[l][r][2] |= dp[l][k][2]&dp[k+1][r][1];
            }
        }
    }

    if(dp[1][n][0]) cout << "yes\n";
    else cout << "no\n";

    memset(dp, 0, sizeof(dp));
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 20;
    while(t--){
        test_case();
    }

    return 0;   
}