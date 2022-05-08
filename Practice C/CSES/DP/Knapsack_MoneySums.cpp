#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18, N = 1e5+10;

int n;
bool dp[N];

int main(void){
    dp[0] = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int w; cin >> w;
        for(int j = 1e5; j >= w; j--)
            dp[j] |= dp[j-w];
    }

    int cnt = 0;
    for(int i = 1; i <= 1e5; i++){
        cnt += dp[i];
    }
    cout << cnt << "\n";
    for(int i = 1; i <= 1e5; i++){
        if(dp[i]) cout << i << " ";
    }
    return 0;
}
