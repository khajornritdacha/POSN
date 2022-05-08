#include <bits/stdc++.h>
using namespace std;

//straight forwardly Fenwick + LCA
//oct_Ringroad

const int N = 2e5+10, LOG = 20;
using pi = pair<int, int>;

int pa[N], dp[N], arr[N], fen[N], n, K, Q, tot, dep[N], ta[N][LOG];
vector<pi> G[N];

void dfs(int u, int p, int an){
    pa[u] = an;
    ta[u][0] = p;
    for(auto [v, w] : G[u]) dp[v] = dp[u]+w, dep[v] = dep[u]+1, dfs(v, u, an);
}

void up(int idx, int val){
    if(idx <= 0) return;
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

int sum(int idx){
    int res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = LOG-1; k >= 0; k--) if(dep[ta[u][k]] >= dep[v]) u = ta[u][k];
    if(u == v) return u;
    for(int k = LOG-1; k >= 0; k--) if(ta[u][k] != ta[v][k]) u = ta[u][k], v = ta[v][k];
    return ta[u][0];
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);   
    cin >> n >> K >> Q;
    for(int i = 1; i <= K; i++){
        dep[i] = 1;
        cin >> arr[i];
        up(i+1, arr[i]);
        tot += arr[i];
    }

    for(int i = K+1; i <= n; i++){
        int p, w; cin >> p >> w;
        G[p].emplace_back(i, w);
    }
    for(int i = 1; i <= K; i++){
        dfs(i, i, i);
    }
    for(int k = 1; k < LOG; k++) for(int i = 1; i <= n; i++) ta[i][k] = ta[ta[i][k-1]][k-1];

    while(Q--){
        int cd, a, b; cin >> cd >> a >> b;
        if(cd == 0){
            up(a+1, b-arr[a]);
            tot += b-arr[a];
            arr[a] = b;
        } else if(cd == 1){
            if(pa[a] != pa[b]){
                if(pa[a] > pa[b]) swap(a, b);
                int tmp = sum(pa[b])-sum(pa[a]);
                int res = min(tmp, tot-tmp);
                cout << res+dp[a]+dp[b] << "\n";
            } else {
                cout << dp[a]+dp[b]-2*dp[lca(a, b)] << "\n";
            }
        }
    }


    return 0;
}