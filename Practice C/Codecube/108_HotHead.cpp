#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 2e5+10;
using ll = long long;
using pi = pair<int,int>;

int n,deg[N];
ll dp[N][3],X;
vector<pi> vec[N];
///https://beta.programming.in.th/tasks/codecube_108

void solve(int u, int p){
    ll mn1 = 1e18, mn2 = 1e18, sum = 0;
    for(auto [v, w] : vec[u]){
        if(v == p) continue;
        solve(v, u);
        sum += min({dp[v][0], dp[v][1], dp[v][2]})+X;

        ll now = min(dp[v][0], dp[v][1])+w-X-min({dp[v][0], dp[v][1], dp[v][2]});
        if(now < mn1) swap(now, mn1);
        if(now < mn2) swap(now, mn2);
    }

    int ch = int(vec[u].size())-(u != p);
    dp[u][0] = dp[u][1] = dp[u][2] = sum;
    dp[u][1] += mn1;
    dp[u][2] += mn1+mn2;
    if(ch < 1) dp[u][1] = 1e18;
    if(ch < 2) dp[u][2] = 1e18;

    if(DEBUG){
        printf("NOW %d\n", u);
        for(int i=0; i<3; i++){
            printf("DP %d = %lld\n", i, dp[u][i]);
        }
        printf("-----------------\n");
    }
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> X;
    int mnw = 1e9, star = 0, st = 1;
    for(int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        mnw = min(mnw, w);
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
        if(++deg[u] == n-1)
            star = u;
        if(++deg[v] == n-1)
            star = v;
    }

    if(star)
        st = star;
    solve(st, st);
    if(star)
        dp[st][0] = dp[st][0]-X+mnw;

    cout << min({dp[st][0], dp[st][1], dp[st][2]});
}
