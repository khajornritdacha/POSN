#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://codeforces.com/problemset/problem/1139/C

int n,K,n_cmp;
vector<pi> G[N];
ll dp[110][N][2],num[N],mod=1e9+7,qs[2];
bool vi[N];

void dfs(int u){
    num[n_cmp]++;
    vi[u] = true;
    for(auto [v, w] : G[u]){
        if(vi[v]) continue;
        if(w == 1) continue;
        dfs(v);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i < n; i++){
        int u,v,w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    for(int i = 1; i <= n; i++){
        if(!vi[i]){
            n_cmp++;
            dfs(i);
        }
    }

    for(int i = 1; i <= n_cmp; i++) dp[1][i][0] = num[i];

    /*for(int i = 2; i <= K; i++){
        for(int cur = 1; cur <= n_cmp; cur++){
            dp[i][cur][0] = (dp[i-1][cur][0]*num[cur])%mod;
            for(int la = 1; la <= n_cmp; la++){
                if(la != cur)
                    dp[i][cur][1] += (dp[i-1][la][0]*num[cur])%mod;
                dp[i][cur][1] += (dp[i-1][la][1]*num[cur])%mod;
                dp[i][cur][1] %= mod;
            }
        }
    }*/

    for(int i = 2; i <= K; i++){
        qs[0] = qs[1] = 0;
        for(int j = 1; j <= n_cmp; j++){
            qs[0] = (qs[0]+dp[i-1][j][0])%mod;
            qs[1] = (qs[1]+dp[i-1][j][1])%mod;
        }

        for(int cur = 1; cur <= n_cmp; cur++){
            dp[i][cur][0] = (dp[i-1][cur][0]*num[cur])%mod;
            dp[i][cur][1] = (num[cur]*qs[1])%mod;
            dp[i][cur][1] += (num[cur]*((qs[0]-dp[i-1][cur][0]+mod)%mod));
            dp[i][cur][1] %= mod;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n_cmp; i++){
        ans = (ans+dp[K][i][1])%mod;
    }
    cout << ans << "\n";
    return 0;
}
