#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long ans;
int nc[N],dp[N],n,st,deg[N];
vector<int> vec[N];
void dfs(int u, int p){
    nc[u] = 1;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u] = max(dp[u], nc[v]);
        nc[u] += nc[v];
    }
    return;
}
void solve(int u, int p){
    int mx[2]={0,0};
    for(int v : vec[u]){
        int val;
        if(v == p)
            val = n-nc[u];
        else
            val = dp[v];
        if(val > mx[0])
            swap(val, mx[0]);
        if(val > mx[1])
            swap(val, mx[1]);
    }
    ans = max(ans, 1ll*mx[0]*mx[1]);
    for(int v : vec[u])
        if(v!=p)
            solve(v, u);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
        deg[u]++; deg[v]++;
    }
    for(int i=1; i<=n; i++){
        if(deg[i] == 1){
            st = i;
            break;
        }
    }
    dfs(st, 0);
    solve(st, 0);
    cout << ans;
}
