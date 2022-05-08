#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int n,m,dp[N],mod = 1e9+7;
bool vi[N];
vector<int> G[N];
stack<int> st;

void dfs(int u){
    vi[u] = true;
    for(int v : G[u]) if(!vi[v]) dfs(v);
    st.push(u);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
    }

    dfs(1);

    dp[1] = 1;
    while(!st.empty()){
        int u = st.top(); st.pop();
        for(int v : G[u]){
            dp[v] = (dp[v] + dp[u])%mod;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}