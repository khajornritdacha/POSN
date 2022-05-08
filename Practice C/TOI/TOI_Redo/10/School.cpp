#include <bits/stdc++.h>
using namespace std;

const int N = 55;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int R,C,O;
ll dp[N][N];
bool a[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> C >> R >> O;
    for(int i = 1; i <= O; i++){
        int r,c; cin >> c >> r;
        a[r][c] = 1;
    }

    dp[1][1] = !a[1][1];
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(i == 1 and j == 1) continue;
            if(a[i][j]) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[R][C] << "\n";

    return 0;   
}