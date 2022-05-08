#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,dp[N];
vector<int> vec[N];

void dfs(int u, int p){
    for(int v : vec[u]){
        dfs(v, u);
        dp[u] += dp[v]+1;
    }
}
main(){
    cin >> n;
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        vec[x].emplace_back(i);
    }
    dfs(1, 1);
    for(int i=1; i<=n; i++){
        cout << dp[i] << " ";
    }
}
