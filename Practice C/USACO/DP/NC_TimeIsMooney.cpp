#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int n,M,C,m[N],dp[N][N];
vector<int> vec[N];
queue<pi> qq;
///http://www.usaco.org/index.php?page=viewproblem2&cpid=993
main(){
    ios_base::sync_with_stdio(0); cin.tie(0); freopen("time.in", "r", stdin); freopen("time.out", "w", stdout);
    cin >> n >> M >> C;
    for(int i=1; i<=n; i++){
        cin >> m[i];
    }
    for(int i=1; i<=M; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
    }
    qq.emplace(1, 0);
    while(!qq.empty()){
        auto [u, t] = qq.front();
        qq.pop();
        if(t+1 > 1001) continue;
        for(int v : vec[u]){
            if(dp[u][t]+m[v] > dp[v][t+1]){
                dp[v][t+1] = dp[u][t]+m[v];
                qq.emplace(v, t+1);
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=1001; i++)
        ans = max(ans, dp[1][i]-C*(i*i));
    cout << ans;
}
