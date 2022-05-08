#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
char K;
string in[15];
ll ans = 3e18;

ll lcm(ll A, ll B){
    return A/__gcd(A, B)*B;
}

void solve(int lv = 1, ll curst = 1, ll lc = 1){
    if(lv == n+1){
        ans = min(ans, curst);
        return;
    }
    ll now = curst;
    for(int i = 0; i < in[lv].size(); i++, now += lc){
        if(now > ans) break; ///Very important line
        if(in[lv][now%in[lv].size()] != K) continue;
        solve(lv+1, now, lcm(lc, in[lv].size()));
    }
}

int main(void){
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> in[i];
    }
    solve();
    cout << ans << "\n";
    return 0;
}
