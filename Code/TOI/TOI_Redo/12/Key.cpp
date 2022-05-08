#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;

int T;
bool dp[N][N];
char A[N],B[N],str[2*N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> (A+1) >> (B+1) >> T;
    int n = strlen(A+1), m = strlen(B+1);
    while(T--){
        cin >> (str+1);
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i >= 1) dp[i][j] |= (str[i+j] == A[i])&dp[i-1][j]; //add A[i] as current
                if(j >= 1) dp[i][j] |= (str[i+j] == B[j])&dp[i][j-1]; //add B[j] as current
            }
        }
        if(dp[n][m]) cout << "Yes\n";
        else cout << "No\n";

        for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = 0;
    }

    return 0;
}