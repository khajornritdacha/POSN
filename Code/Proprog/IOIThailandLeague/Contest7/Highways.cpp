#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
const int N = 1e5+10;

vector<tu> vec[N];
vector<tu> edge;
pi use[N];
int dp[N],st,n,m;
long long ans,sum;

void dfs(int u, int p){
    dp[u] = 1;
    for(int i=0; i<vec[u].size(); i++){
        int v,w,idx;
        tie(v,w,idx) = vec[u][i];
        if(v == p) continue;
        dfs(v, u);
        ans += 1ll*(n-dp[v])*dp[v]*w;
        use[idx] = {dp[v], w};
        dp[u] += dp[v];
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w, i);
        vec[v].emplace_back(u, w, i);
        edge.emplace_back(u, v, w);
    }
    for(int i=0; i<n; i++){
        if(vec[i].size() == 1){
            st = i;
            break;
        }
    }
    dfs(st, -1);
    /*for(int i=0; i<n; i++){
        cout << dp[i] << " \n"[i==n-1];
    }
    cout << "ANS : " << ans << "\n";*/
    cin >> m;
    for(int i=1; i<=m; i++){
        int idx,val,mul,w;
        cin >> idx >> val;
        tie(mul, w) = use[idx];
        ans += 1ll*(n-mul)*mul*(val-w);
        cout << ans << "\n";
        use[idx].second = val;
    }
}
