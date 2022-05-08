#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1010;
const ll INF = 1e18;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,X,Y,ix[N],iy[N];
ll c[N],dp[2][505][505];
//Knapsack
main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> X >> Y;
    for(int i = 1; i <= n; i++){
        cin >> ix[i] >> iy[i] >> c[i];
    }
    
    for(int i = 0; i <= 1; i++) for(int x = 0; x <= X; x++) for(int y = 0; y <= Y; y++) dp[i][x][y] = INF;
    
    dp[1][0][0] = 0;

    for(int i = 1; i <= n; i++){
        int cur = i&1;
        for(int x = 0; x <= X; x++) for(int y = 0; y <= Y; y++){
            dp[1-cur][x][y] = INF;
        }
        dp[1-cur][0][0] = 0;
        for(int x = 0; x <= X; x++){
            for(int y = 0; y <= Y; y++){
                if(dp[cur][x][y] >= INF) continue;
                int gx = min(X, x+ix[i]), gy = min(Y, y+iy[i]);
                dp[1-cur][gx][gy] = min(dp[1-cur][gx][gy], dp[cur][x][y] + c[i]);
                dp[1-cur][x][y] = min(dp[1-cur][x][y], dp[cur][x][y]);
            }
        }
    }

    ll res = dp[(n+1)%2][X][Y];
    if(res >= INF) res = -1;
    cout << res << "\n";

    return 0;

}
