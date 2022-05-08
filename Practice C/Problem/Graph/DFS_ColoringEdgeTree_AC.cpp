#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int ans[N], n, m, mx;
vector<pair<int,int>> G[N];

//https://atcoder.jp/contests/abc146/tasks/abc146_d

void add(int &x){
    if(x == mx) x = 1;
    else x++;
}

void dfs(int u, int p, int b = 0){
    int cur = 1;
    if(cur == b) add(cur);
    for(auto [v, idx] : G[u]){
        if(v == p) continue;
        ans[idx] = cur;
        dfs(v, u, cur);

        add(cur);
        if(cur == b) add(cur);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    for(int i = 1; i <= n; i++) mx = max(mx, (int)G[i].size());

    dfs(1, -1);

    cout << mx << "\n";
    for(int i = 1; i < n; i++) cout << ans[i] << "\n";

    return 0;
}