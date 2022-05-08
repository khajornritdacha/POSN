#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int n,dp[N],cc[N];
vector<int> vec[N];

void dfs(int u, int p){
    int mx1=0,mx2=0;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
        cc[u] = max(cc[u], cc[v]);
        dp[u] = max(dp[u], dp[v]);
        int tmp = cc[v];
        if(tmp >= mx1)
            swap(tmp, mx1);
        if(tmp >= mx2)
            swap(tmp, mx2);
    }
    cc[u]++;
    dp[u] = max(dp[u], mx1+mx2+1);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=2; i<=n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    dfs(1, 1);
    cout << dp[1]-1 << "\n";

    if(DEBUG){
        for(int i=1; i<=n; i++){
            cout << cc[i] << " \n"[i==n];
        }
        for(int i=1; i<=n; i++){
            cout << dp[i] << " \n"[i==n];
        }
    }
}
