#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int dp[N][2],t,n,ans,tmp,st,ed,go[N];
bool visit[N],code;
vector<vector<int>> vec;
void cls(int u){
    visit[u] = false;
    for(int v : vec[u]){
        if(visit[v])
            cls(v);
    }
}
void solve(int u, int p){
    visit[u] = true;
    dp[u][0] = 1;
    dp[u][1] = 0;
    for(int v : vec[u]){
        if(v==p) continue;
        if(visit[v]) continue;
        solve(v, u);
        dp[u][0] += min(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    if(u == ed && code == 1)
        dp[u][1] = 1e9;
    return;
}
void cycle(int u){
    visit[u] = true;
    if(!visit[go[u]]){
        cycle(go[u]);
    }else{
        st = u;
        ed = go[u];
    }
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        vec.clear();
        vec.resize(n+1);
        for(int i=1; i<=n; i++){
            cin >> go[i];
            vec[go[i]].emplace_back(i);
        }
        for(int i=1; i<=n; i++){
            if(visit[i]) continue;
            cycle(i);
            //printf("St : %d and %d\n", st,ed);
            cls(st);
            code = 0;
            solve(st, -1);
            //printf("TMP : %d and %d\n", dp[st][0], dp[st][1]);
            tmp = dp[st][0];
            cls(st);
            code = 1;
            solve(st, -1);
            tmp = min(tmp, dp[st][1]);
            //printf("TMP : %d and %d\n", dp[st][0], dp[st][1]);
            ans+=tmp;
        }
        cout << ans << "\n";
        for(int i=1; i<=n; i++)
            visit[i] = 0;
    }
}
///https://beta.programming.in.th/tasks/codecube_154
