#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010;
using ll = long long;
using pi = pair<int,int>;

int R,C,K,qs[N][N];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> K;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> qs[i][j];
            qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i = K; i <= R; i++){
        for(int j = K; j <= C; j++){
            ans = max(ans, qs[i][j] - qs[i-K][j] - qs[i][j-K] + qs[i-K][j-K]);
        }
    }
    cout << ans << "\n";
    return 0;
}