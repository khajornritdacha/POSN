#include <iostream>
#include <algorithm>
using namespace std;

const int N = 7010;
int R,C,ep[N],dp[N][N];
char a[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> a[i][j];
            ep[1] += (a[i][j] == '1');
        }
    }
    for(int i=R; i>=1; i--){
        for(int j=C; j>=1; j--){
            if(a[i][j] == '0') continue;
            dp[i][j] = min({dp[i+1][j+1], dp[i+1][j], dp[i][j+1]})+1;
            ep[min({dp[i][j]+1, R-i+2, C-j+2})]--;
        }
    }

    int ans = 0;
    for(int i=1; i<=min(R, C); i++){
        ans += ep[i];
        cout << ans << "\n";
    }
    return 0;
}
