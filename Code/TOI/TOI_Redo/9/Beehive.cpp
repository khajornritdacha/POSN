#include <bits/stdc++.h>
using namespace std;

const int N = 1010, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int a[N][N], R, C;
pi dp[N][N];

int main(void){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i <= R; i++) for(int j = 0; j <= C; j++) dp[i][j] = pi(-INF, 0);

    for(int j = 1; j <= C; j++) dp[1][j] = pi(a[1][j], 1);

    for(int i = 2; i <= R; i++){
        int dc = (i&1) ? -1 : 1;
        for(int j = 1; j <= C; j++){
            if(dp[i-1][j].first > dp[i-1][j+dc].first) dp[i][j] = pi(dp[i-1][j].first + a[i][j], dp[i-1][j].second);
            else if(dp[i-1][j].first < dp[i-1][j+dc].first) dp[i][j] = pi(dp[i-1][j+dc].first + a[i][j], dp[i-1][j+dc].second);
            else if(dp[i-1][j].first == dp[i-1][j+dc].first) dp[i][j] = pi(dp[i-1][j].first + a[i][j], dp[i-1][j].second + dp[i-1][j+dc].second);
        }
    }

    int mx = -1, cnt = 0;
    for(int j = 1; j <= C; j++){
        if(dp[R][j].first > mx){
            mx = dp[R][j].first;
            cnt = dp[R][j].second;
        } else if(dp[R][j].first == mx){
            cnt += dp[R][j].second;
        }
    }

    cout << mx << " " << cnt << "\n";
    return 0;
}