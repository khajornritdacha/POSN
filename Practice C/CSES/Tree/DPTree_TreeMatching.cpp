#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
int dp[N][2],V;
vector<int> vec[N];
///dp(u, 0) is the maximum number of pairs we can form if we do not use edge between u and any child
///dp(u, 1) is the maximum number of pairs we can form if we use edge between u and one of its child

void dfs(int u, int p){
    bool pus = false;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        if(!pus and dp[v][0] >= dp[v][1]){
            pus = true;
            dp[u][1] += dp[v][0]+1;
        }else{
            dp[u][1] += max(dp[v][0], dp[v][1]);
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V;
    for(int i=1; i<V; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]);
}
