#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18, N = 5010;

int dp[N][N];
string A,B;

int main(void){
    cin >> A >> B;
    for(int i = 0; i <= A.size(); i++){
        for(int j = 0; j <= B.size(); j++){
            dp[i][j] = 1e9;
            if(i == 0){
                dp[i][j] = j;
            }else if(j == 0){
                dp[i][j] = i;
            }else{
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1];
                dp[i][j] = min({dp[i][j], dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1});
            }
        }
    }

    /*for(int i = 0; i <= A.size(); i++){
        for(int j = 0; j <= B.size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/

    cout << dp[A.size()][B.size()] << "\n";
    return 0;
}
