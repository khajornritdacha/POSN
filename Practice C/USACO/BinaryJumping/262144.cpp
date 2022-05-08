#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 3e5 + 10;
using ll = long long;

int n, a[N], dp[N][2];

int main(void){
    freopen("262144.in", "r", stdin);
    freopen("262144.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }    

    int mx = 0;
    for(int k = 1; k <= 60; k++){
        int cur = k%2;
        for(int i = 1; i <= n; i++){
            dp[i][cur] = 0;
            if(k == a[i]){
                dp[i][cur] = i;
            } else if (dp[i][1-cur]){
                dp[i][cur] = dp[dp[i][1-cur]-1][1-cur];
            }

            if(dp[i][cur] > 0)
                mx = k;
        }
    }

    cout << mx << "\n";
    return 0;
}