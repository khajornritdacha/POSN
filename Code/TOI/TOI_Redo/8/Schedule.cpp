#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int N = 1010, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int M,n,a[2][N];
pi dp[N][N];

int main(void){
    cin >> M >> n;
    for(int t : {0, 1}){
        for(int i = 1; i <= n; i++){
            cin >> a[t][i];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i != 0 or j != 0)
                dp[i][j] = {INF, INF};
            
            if(i >= 1){
                int td = dp[i-1][j].F, tm = dp[i-1][j].S + a[0][i];
                if(tm > M){
                    td++;
                    tm = a[0][i];
                }

                dp[i][j] = min(dp[i][j], pi(td, tm));
            }

            if(j >= 1){
                int td = dp[i][j-1].F, tm = dp[i][j-1].S + a[1][j];
                if(tm > M){
                    td++;
                    tm = a[1][j];
                }

                dp[i][j] = min(dp[i][j], pi(td, tm));
            }
        }
    }

    cout << dp[n][n].F+1 << "\n" << dp[n][n].S << "\n";
    return 0;
}