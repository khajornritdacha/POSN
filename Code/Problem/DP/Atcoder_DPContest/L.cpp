#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
using lb = long double;
using ll = long long;

int n;
bool vi[N][N];
ll dp[N][N],a[N];

ll solve(int l, int r, bool cur = 0){
    if(l > r) return 0;
    if(vi[l][r]) return dp[l][r];
    vi[l][r] = true;
    ll tmp;
    if(!cur){
        tmp = max(solve(l+1, r, !cur)+a[l], solve(l, r-1, !cur)+a[r]);
    }else{
        tmp = min(solve(l+1, r, !cur)-a[l], solve(l, r-1, !cur)-a[r]);
    }
    return dp[l][r] = tmp;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << solve(1, n) << "\n";

   /* for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    return 0;
}
