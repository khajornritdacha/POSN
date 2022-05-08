#include <bits/stdc++.h>
using namespace std;

const int N = 21;
using lb = long double;
using ll = long long;

int n,a[N][N];
int dp[N][(1<<N)],mod=1e9+7;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        if(a[0][i]){
            dp[0][(1<<i)] = 1;
        }
    }
    for(int i = 0; i < n-1; i++){
        for(int bit = 0; bit < (1<<n); bit++){
            if(__builtin_popcount(bit) != i+1) continue; ///Super Optimization
            for(int j = 0; j < n; j++){
                if((bit&(1<<j)) != 0) continue;
                if(a[i+1][j] == 0) continue;
                //cout << i << " " << j << " " << bit << "\n";
                dp[i+1][(bit|(1<<j))]+=dp[i][bit];
                if(dp[i+1][(bit|(1<<j))] >= mod)
                    dp[i+1][(bit|(1<<j))] -= mod;
            }
        }
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < 1<<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << dp[n-1][(1<<n)-1];
    return 0;
}
