#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

using pi = pair<int, int>;

int n, K, a[N][N], dp[3][N][N];

//precalculate minimum for (i, j) from (i-K+1, j) to (i+K-1, j) 
//then use another dq to find minimum from (i, j) to (i, j+K-1)

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;

    for(int t = 0; t < 3; t++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
   
        deque<pi> dqr[n+5];

        for(int r = K, sr = 0; r <= n; r++){
            for(int c = K; c <= n; c++){
                while(!dqr[c].empty() and dqr[c].front().first < r-K+1) dqr[c].pop_front();
            }

            while(sr+1 <= r and sr+K-1 <= n){
                sr++;
                for(int c = K; c <= n; c++){
                    int val = a[sr+K-1][c]-a[sr+K-1][c-K]-a[sr-1][c]+a[sr-1][c-K];
                    while(!dqr[c].empty() and dqr[c].back().second < val) dqr[c].pop_back();
                    dqr[c].emplace_back(sr, val);  
                }
            }

            deque<pi> dqc;
            for(int c = K, sc = K-1; c <= n; c++){
                while(!dqc.empty() and dqc.front().first < c) dqc.pop_front();
                
                while(sc+1 <= c+K-1 and sc+1 <= n){
                    sc++;
                    while(!dqc.empty() and !dqr[sc].empty() and dqc.back().second < dqr[sc].front().second) dqc.pop_back();
                    dqc.emplace_back(sc, dqr[sc].front().second);
                }

                dp[t][r][c] = dqc.front().second;
            }
        }
    }

    int ans = 0;
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            ans = max(ans, dp[0][r][c] + dp[1][r][c] + dp[2][r][c]);
        }
    }
    cout << ans << "\n";



    return 0;
}