#include <bits/stdc++.h>
using namespace std;

const int N = 110;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int a[N][N], dr[6] = {-1, -1, 0, 0, 1, 1}, dc[2][6] = {{-1, 0, -1, 1, -1, 0}, {0, 1, -1, 1, 0, 1}}, R, C;
bool di[10][5010], dp[2][N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }

    for(int i : {-1, 0, 1}){
        if(a[R/2 + i + 1][1] == 1){
            dp[1][R/2 + i + 1][1] = 1;
        }
    }

    for(int i = 1; i <= 9; i++) for(int j = i; j <= 5000; j += i) di[i][j] = true; //pre calculate instead of using modulo

    for(int t = 2; ; t++){
        int cur = t&1, pre = t-1;

        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                dp[cur][i][j] = 0;
                for(int k = 0; k < 6; k++){
                    int r = i+dr[k], c = j+dc[i&1][k];
                    
                    if(di[a[i][j]][t]) 
                        dp[cur][i][j] |= dp[1-cur][r][c];                        
                }
            }
        }

        if(dp[cur][R/2 + 1][C]){
            cout << t << "\n";
            return 0;
        }
    }
    return 0;   
}