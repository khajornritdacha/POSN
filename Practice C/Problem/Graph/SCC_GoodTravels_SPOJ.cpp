#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;
using pi = pair<ll, ll>;
int disc[N],low[N],ti,n,m,no_cmp,cmp[N],fun[N],FI,LA;
ll sum[N],dis[N];
bool inST[N];
vector<pi> edge;
vector<int> vec[N];
set<int> re[N];
stack<int> st;
///https://www.spoj.com/problems/GOODA/

void tar(int u){
    disc[u] = low[u] = ++ti;
    inST[u] = true;
    st.push(u);
    for(int v : vec[u]){
        if(!disc[v]){
            tar(v);
            low[u] = min(low[u], low[v]);
        }
        if(inST[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(low[u] == disc[u]){
        ++no_cmp;
        while(true){
            int now = st.top();
            inST[now] = false;
            st.pop();
            cmp[now] = no_cmp;
            sum[no_cmp] += fun[now];
            if(now == u)
                break;
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> FI >> LA;
    for(int i=1; i<=n; i++){
        cin >> fun[i];
    }
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        edge.emplace_back(u, v);
    }
    tar(FI);
    for(auto [u, v] : edge){
        if(cmp[u] == cmp[v]) continue;
        re[cmp[u]].insert(cmp[v]);
    }

    priority_queue<pi> pq;
    pq.emplace(0, cmp[FI]);
    while(!pq.empty()){
        auto [wa, u] = pq.top();
        pq.pop();
        if(dis[u] != wa) continue;
        dis[u] += sum[u];
        for(int v : re[u]){
            if(dis[u] > dis[v]){
                dis[v] = dis[u];
                pq.emplace(dis[v], v);
            }
        }
    }
    cout << dis[cmp[LA]];
}
