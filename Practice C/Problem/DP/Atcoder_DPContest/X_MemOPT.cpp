#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1010;

struct DATA{
    int w,s,v;
    bool operator<(const DATA &other){
        if(w+s != other.w+other.s) return w+s > other.w+other.s;
        return v > other.v;
    }
};

int n;
ll dp[N][10*N];
DATA blocks[N];


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int w,s,v; cin >> w >> s >> v;
        blocks[i] = {w, s, v};
    }
    sort(blocks+1, blocks+n+1);

    ll ans = 0;
    vector<ll> dp(1e4+10);
    for(int i = n; i >= 1; i--){
        ans = max(ans, dp[blocks[i].s]+blocks[i].v);
        vector<ll> ndp(dp.size());
        for(int j = 1; j <= 1e4; j++){
            ndp[j] = dp[j];
            if(j >= blocks[i].w)
                ndp[j] = max(ndp[j], dp[min(blocks[i].s, j-blocks[i].w)]+blocks[i].v);
        }
        dp = ndp;
    }
    cout << ans << "\n";
    return 0;
}
