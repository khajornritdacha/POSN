#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+10;
using pi = pair<int,int>;
int n,disc[N],low[N],ti,cmp[N],co[N],nc,m;
long long dp[N],pr[N];
vector<pi> edge;
vector<int> vec[N];
set<int> go[N];
stack<int> st;
bool in_ST[N],vi[N];

void dfs(int u){
    disc[u] = low[u] = ++ti;
    in_ST[u] = true;
    st.push(u);
    for(int v : vec[u]){
        if(!disc[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        if(in_ST[v]){
            low[u] = min(low[u], disc[v]);
        }
    }

    if(low[u] == disc[u]){
        ++nc;
        while(true){
            int now = st.top();
            st.pop();
            in_ST[now] = false;
            cmp[now] = nc;
            pr[nc] += co[now];
            if(now == u)
                break;
        }
    }
}

void topo(int u){
    vi[u] = true;
    for(int v : go[u]){
        if(!vi[v])
            topo(v);
    }
    st.push(u);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> co[i];
    }
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        edge.emplace_back(u, v);
    }

    for(int i=1; i<=n; i++){
        if(!disc[i]){
            dfs(i);
        }
    }

    //cout << "NC : " << nc << "\n";
    for(auto [u, v] : edge){
        if(cmp[u] != cmp[v])
            go[cmp[u]].insert(cmp[v]);
    }

    for(int i=1; i<=nc; i++){
        if(!vi[i])
            topo(i);
    }

    long long ans = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        dp[u] += pr[u];
        for(int v : go[u]){
            dp[v] = max(dp[u], dp[v]);
        }
        ans = max(ans, dp[u]);
    }

    cout << ans << "\n";
}
