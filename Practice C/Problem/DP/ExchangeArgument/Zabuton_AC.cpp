#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://atcoder.jp/contests/cf17-final/tasks/cf17_final_d

struct DATA{
    int H,P;
};

int n;
DATA a[N];
ll dp[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].H >> a[i].P;
    }
    sort(a+1, a+n+1, [&](const DATA &A, const DATA &B){
        return A.H+A.P < B.H+B.P;
    });

    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = 1e18;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int num = 1; num <= i; num++){
            dp[i][num] = dp[i-1][num];
            if(dp[i-1][num-1] <= a[i].H)
                dp[i][num] = min(dp[i][num], dp[i-1][num-1]+a[i].P);
        }
    }

    int ans = 0;
    for(int i = n; i >= 1; i--){
        if(dp[n][i] != 1e18){
            ans = i; break;
        }
    }
    cout << ans << "\n";
    /*for(int i = 1; i <= n; i++){
        cout << a[i].H << " " << a[i].P << "\n";
    }*/
    return 0;
}
