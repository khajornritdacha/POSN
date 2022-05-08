#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,m,disc[N],low[N],ti,no_cmp,cmp[N],dp[N];
bool inST[N];
stack<int> st;
vector<int> mem_cmp[N],vec[N];
set<int> re[N];
vector<pair<int,int>> edge;
///https://www.spoj.com/problems/CAPCITY/
void tar(int u){
    disc[u] = low[u] = ++ti;
    inST[u] = true;
    st.push(u);
    for(int v : vec[u]){
        if(!disc[v]){
            tar(v);
            low[u] = min(low[u], low[v]);
        }else if(inST[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(disc[u] == low[u]){
        no_cmp++;
        while(true){
            int now = st.top();
            st.pop();
            inST[now] = false;
            cmp[now] = no_cmp;
            mem_cmp[no_cmp].emplace_back(now);
            if(now == u)
                break;
        }
    }
}

int dfs(int u){
    //cout << "U : " << u << "\n";
    if(dp[u])
        return dp[u];
    dp[u] = 1;
    for(int v : re[u]){
        dp[u] += dfs(v);
    }
    return dp[u];
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        edge.emplace_back(u, v);
    }
    for(int i=1; i<=n; i++){
        if(!disc[i]){
            tar(i);
        }
    }
    for(auto [u, v] : edge){
        if(cmp[u] == cmp[v]) continue;
        re[cmp[v]].insert(cmp[u]);
    }

    //cout << "NO : " << no_cmp << "\n";

    for(int i=1; i<=no_cmp; i++){
        if(!dp[i]){
            dfs(i);
            if(dp[i] == no_cmp){
                cout << mem_cmp[i].size() << "\n";
                sort(mem_cmp[i].begin(), mem_cmp[i].end());
                for(int v : mem_cmp[i])
                    cout << v << " ";
                return 0;
            }
        }
    }
    cout << 0;
}
