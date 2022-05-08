#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
using pi = pair<int,int>;
using ll = long long;

int n,M,K,a[110],cnt[N];
vector<pi> G[N];
ll dp[200010],mod = 998244353;

bool dfs(int u, int p, int tar){
    if(u == tar){ return true;}
    for(auto [v, idx] : G[u]){
        if(v == p) continue;
        if(dfs(v, u, tar)){
            cnt[idx]++;
            return true;
        }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M >> K;

    for(int i = 1; i <= M; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    for(int i = 1; i < M; i++){
        dfs(a[i], a[i], a[i+1]);
    }

    int tot = 0;
    for(int i = 1; i < n; i++){
        tot += cnt[i];
        //cout << cnt[i] << "\n";
    }
    //cout << "TOT : " << tot << "\n";

    if((K+tot)%2 != 0 or (K+tot) < 0){
        cout << 0; return 0;
    }

    dp[0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 2e5; j >= cnt[i]; j--){
            dp[j] = (dp[j]+dp[j-cnt[i]])%mod;
        }
    }
    cout << dp[(K+tot)/2] << "\n";
    return 0;
}
