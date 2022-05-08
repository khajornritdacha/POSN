#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
using ll = long long;
const ll INF = 1e9;

//https://dmoj.ca/problem/apio09p3

int n,m,S,P,low[N],val[N],id[N],scc_id[N],num,ti;
int cost[N];
bitset<N> pub,chk,in_st;
stack<int> st;
vector<int> oG[N],nG[N];

void SCC(int u){
    low[u] = id[u] = ++ti;
    in_st[u] = true;
    st.push(u);
    for(int v : oG[u]){
        if(!id[v]) SCC(v);
        if(in_st[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == id[u]){
        num++;
        while(true){
            int now = st.top(); st.pop();
            scc_id[now] = num;
            in_st[now] = false;
            pub[num] = pub[num]|chk[now];
            cost[num] += val[now];
            if(now == u) break;
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        oG[u].emplace_back(v);
    }
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }
    cin >> S >> P;
    for(int i = 1; i <= P; i++){
        int u; cin >> u;
        chk[u] = true;
    }

    SCC(S);

    for(int i = 1; i <= n; i++){
        if(!id[i]) continue;
        for(int v : oG[i]){
            if(scc_id[v] != scc_id[i]) nG[scc_id[i]].emplace_back(scc_id[v]);
        }
    }

    for(int i = 1; i <= num; i++) val[i] = -INF;

    for(int i = 1; i <= num; i++){
        if(pub[i]) val[i] = max(val[i], 0);
        for(int v : nG[i]) val[i] = max(val[i], val[v]);
        if(val[i] >= 0) val[i] += cost[i];
    }

    cout << val[scc_id[S]] << "\n";

    return 0;
}