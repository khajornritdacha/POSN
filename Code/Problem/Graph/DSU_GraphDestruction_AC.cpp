#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, m, ans[N], cp[N];
vector<int> G[N];

//https://atcoder.jp/contests/abc229/tasks/abc229_e

int fi(int x){ return cp[x] = (cp[x] == x) ? x : fi(cp[x]); }

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v) return false;
    cp[v] = u;
    return true;
}

int main(void){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= n; i++) cp[i] = i;

    int cnt = 0;
    for(int i = n; i >= 2; i--){
        cnt++;
        for(int v : G[i]){
            if(v < i) continue;
            if(uni(i, v)) cnt--;
        }
        ans[i-1] = cnt;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";

    return 0;
}