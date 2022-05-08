#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int dp[N],ans[N],n,ch[N];
vector<int> vec[N];

int fisum(int u, int p){
    int tmp = 0;
    ch[u] = 1;
    for(int v : vec[u]){
        if(v == p) continue;
        dp[u] += fisum(v, u)+ch[v];
        ch[u] += ch[v];
    }
    return dp[u];
}

void dfs(int u, int p){
    if(u != 1)
        ans[u] = ans[p]-ch[u]*2+n;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    fisum(1, -1);
    ans[1] = dp[1];
    dfs(1, -1);

    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}
