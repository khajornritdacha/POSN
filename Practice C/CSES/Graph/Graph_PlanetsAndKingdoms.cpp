#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using pi = pair<int, int>;
int cmp[N],low[N],disc[N],ti,no_cmp,n,m;
bool inST[N];
vector<int> vec[N];
vector<pi> edge;
stack<int> st;

void tar(int u){
    disc[u] = low[u] = ++ti;
    inST[u] = true;
    st.push(u);
    for(int v : vec[u]){
        if(disc[v] == -1){
            tar(v);
            low[u] = min(low[u], low[v]);
        }
        if(inST[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    //cout << u << " = " << disc[u] << " " << low[u] << "\n";
    if(low[u] == disc[u]){
        no_cmp++;
        while(true){
            int now = st.top();
            st.pop();
            inST[now] = false;
            cmp[now] = no_cmp;
            if(now == u)
                break;
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(disc, -1, sizeof(disc));
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        edge.emplace_back(u, v);
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == -1){
            //cout << "ST : " << i << "\n";
            tar(i);
        }
    }
    cout << no_cmp << "\n";
    for(int i=1; i<=n; i++){
        cout << cmp[i] << " \n"[i==n];
    }
}
