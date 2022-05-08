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
    for(int i = n; i >= 1; i--){
        //dp[i][blocks[i].s] = blocks[i].v+dp[i+1][blocks[i].s];
        for(int j = 1; j <= 1e4; j++){
            dp[i][j] = max(dp[i][j], dp[i+1][j]);
            if(j >= blocks[i].w)
                dp[i][j] = max(dp[i][j], dp[i+1][min(blocks[i].s, j-blocks[i].w)]+blocks[i].v);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i+1][blocks[i].s]+blocks[i].v);
    cout << ans << "\n";
    /*for(int i = 1; i <= n; i++){
        cout << "I " << i << " = " << blocks[i].w << " " << blocks[i].s << " "  << blocks[i].v << "\n";
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 10; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    return 0;
}
