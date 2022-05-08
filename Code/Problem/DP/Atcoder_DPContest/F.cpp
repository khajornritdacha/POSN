#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string A,B;
    cin >> A >> B;
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n+5, vector<int>(m+5, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int r = n, c = m;
    vector<char> ans;

    while(r > 0 and c > 0){
        if(A[r-1] == B[c-1]){ ///Very important can't change to dp[i][j] == dp[i-1][j-1]+1
            ans.emplace_back(A[r-1]); ///Because comparing numbers doesn't guarantee that they are the same character.
            r--, c--;
        }else if(dp[r-1][c] >= dp[r][c-1]){
            r--;
        }else{
            c--;
        }
    }
    while(!ans.empty()){
        cout << ans.back();
        ans.pop_back();
    }
    cout << "\n";
    return 0;
}
