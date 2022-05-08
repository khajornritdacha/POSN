#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 55;

int n,K;
string dp[N][N],s[N];

///https://atcoder.jp/contests/abc225/tasks/abc225_f

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;

    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }

    sort(s+1, s+n+1, [&](const string &A, const string &B){
        return A+B < B+A;
    });

    /*for(int i = 1; i <= n; i++){
        cout << s[i] << "\n";
    }*/

    for(int i = n; i >= 1; i--){
        for(int k = 1; k <= n-i+1 and k <= K; k++){
            if(dp[i+1][k].size() == 0){
                dp[i][k] = s[i]+dp[i+1][k-1];
                //cout << i << " " << k << "\n";
            }else{
                dp[i][k] = min(dp[i+1][k], s[i]+dp[i+1][k-1]);
            }
        }
    }


    if(DEBUG){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << dp[1][K] << "\n";
    return 0;
}
