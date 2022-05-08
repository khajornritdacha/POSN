#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e6+10;
const ll INF = 1e9;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,U,V;
char c[N];
map<int,int> mp[2];
vector<int> G[N];

void dfs(int u, int cd, int cur = 0, int p = -1){
    if(cur != INF and cd == 0){
         if(c[u] == '(') cur++;
         else cur--;
         if(cur < 0) cur = INF;
    } else if(cur != INF and cd == 1){
        if(c[u] == ')') cur++;
        else cur--;
        if(cur < 0) cur = INF;
    }
    if(cur != INF)
        mp[cd][cur]++;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, cd, cur, u);
    }
    return;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> U >> V;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++) cin >> c[i];

    dfs(U, 0);
    
    dfs(V, 1);

    long long ans = 0;
    for(auto [val, cnt] : mp[1]){
        if(val < INF and mp[0].count(val)){
            ans += 1ll*mp[0][val]*mp[1][val];
        }
    }
    cout << ans << "\n";

    return 0;
}
