#include <bits/stdc++.h>
using namespace std;

const int N = 2010, MXC = 1e5+10;

int n, m;
long long dp[MXC], INF = 1e18;

//perform knapsack on set that includes both available computers and orders and sort by F first if F is equal then let available computer come first

struct DATA{
    int c, f, v;
};

DATA arr[2*N];

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].c >> arr[i].f >> arr[i].v;
        arr[i].v *= -1;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> arr[i+n].c >> arr[i+n].f >> arr[i+n].v;
    }

    for(int i = 1; i < MXC; i++) dp[i] = -INF;

    sort(arr+1, arr+n+m+1, [&](const DATA &A, const DATA &B){
        if(A.f != B.f) return A.f > B.f;
        return A.v < B.v;
    });

    for(int i = 1; i <= n+m; i++){
        if(arr[i].v < 0){
            for(int j = MXC-1; j >= arr[i].c; j--){
                if(dp[j-arr[i].c] <= -INF) continue;
                dp[j] = max(dp[j], dp[j-arr[i].c]+arr[i].v);    
            }
        } else {
            for(int j = 0; j+arr[i].c < MXC; j++){
                if(dp[j+arr[i].c] <= -INF) continue;
                dp[j] = max(dp[j], dp[j+arr[i].c]+arr[i].v);
            }
        }
    }

    long long ans = 0;
    for(int j = 0; j < MXC; j++) ans = max(ans, dp[j]);
    cout << ans << "\n";

    return 0;
}