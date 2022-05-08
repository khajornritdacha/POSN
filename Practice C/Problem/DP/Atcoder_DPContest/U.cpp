#include <bits/stdc++.h>
using namespace std;

const int N = 16;
using ll = long long;

int n,a[N][N];
ll cost[1<<N],dp[1<<N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int bit = 0; bit < 1<<n; bit++){
        dp[bit] = -1e18;
        for(int i = 0; i < n; i++){
            if(bit&(1<<i)) continue;
            ll sum = 0;
            for(int j = 0; j < n; j++){
                if(bit&(1<<j))
                    sum += a[i][j];
            }
            cost[bit|(1<<i)] = cost[bit]+sum;
        }
    }
    dp[0] = 0;
    for(int bit = 0; bit < 1<<n; bit++){
        for(int now = bit; ; now=(now-1)&bit){ ///Enumerate all submasks in only O(3^n)
            int add = bit&(~now);
            dp[bit] = max(dp[bit], dp[now]+cost[add]);
            if(now == 0) break;
        }
    }
    cout << dp[(1<<n)-1];
    return 0;
}
