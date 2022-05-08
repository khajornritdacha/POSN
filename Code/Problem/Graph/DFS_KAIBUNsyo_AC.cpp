#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

int a[N],n,ans,sz;
bool vi[N];
vector<int> G[N];

///https://atcoder.jp/contests/abc206/tasks/abc206_d
/// 6 Nov 2021

void dfs(int u){
    sz++;
    vi[u] = true;
    for(int v : G[u]){
        if(!vi[v]) dfs(v);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1, lim = n/2; i <= lim; i++){
        G[a[i]].emplace_back(a[n-i+1]);
        G[a[n-i+1]].emplace_back(a[i]);
    }

    for(int i = 1; i <= n; i++){
        if(!vi[a[i]]){
            sz = 0;
            dfs(a[i]);
            ans += sz-1;
        }
    }

    cout << ans << "\n";
    return 0;
}
