#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 5010;
using pi = pair<int,int>;

int ti,disc[N],low[N],n,P,idx,cmp[N],mb[N],ans[N],lv[N];
bool in_ST[N],vi[N];
vector<int> vec[N];
set<int> g[N];
stack<int> st;

void dfs(int u){
    in_ST[u] = true;
    disc[u] = low[u] = ++ti;
    st.push(u);
    for(int v : vec[u]){
        if(!disc[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else if(in_ST[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(low[u] == disc[u]){
        idx++;
        while(true){
            int now = st.top(); st.pop();
            in_ST[now] = false;
            cmp[now] = idx;
            mb[cmp[now]]++;
            if(now == u) break;
        }
    }
}

void topo(int u){
    vi[u] = true;
    for(int v : g[u]){
        if(vi[v]) continue;
        topo(v);
    }
    st.push(u);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> P;
    for(int i=1; i<=P; i++){
        int u,v; cin >> u >> v;
        u++, v++;
        vec[u].emplace_back(v);
    }
    for(int i=1; i<=n; i++){
        if(!disc[i]){
            dfs(i);
        }
    }

    if(DEBUG){
        cout << "CMP\n";
        for(int i=1; i<=n; i++){
            cout << cmp[i] << " ";
        }
        cout << "\nSZ\n";
        for(int i=1; i<=idx; i++){
            cout << mb[i] << " ";
        }
        cout << "\n----------------------\n";
    }

    for(int i=1; i<=n; i++){
        for(int v : vec[i]){
            if(cmp[i] != cmp[v])
                g[cmp[i]].insert(cmp[v]);
        }
    }
    for(int i=1; i<=idx; i++){
        if(!vi[i]){
            topo(i);
        }
    }
    int mx = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        //cout << "NOW : " << u << "\n";
        ans[lv[u]] += mb[u];
        mx = max(mx, lv[u]);
        for(int v : g[u]){
            lv[v] = max(lv[v], lv[u]+1);
        }
    }

    if(DEBUG){
        cout << "Go\n";
        for(int i=1; i<=idx; i++){
            cout << "I " << i << " : ";
            for(int v : g[i]){
                cout << v << " ";
            }
            cout << "\n";
        }
        cout << "--------------------\n";
        cout << "LV : ";
        for(int i=1; i<=idx; i++){
            cout << lv[i] << " ";
        }
        cout << "\n";
        cout << "--------------------\n";
    }
    for(int i=0; i<=mx; i++)
        cout << ans[i] << " ";
}
