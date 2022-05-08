#include <bits/stdc++.h>
using namespace std;

const int N = 2e4+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int n,m,id[N],low[N],scc_id[N],num,ti;
bool in_st[N];
vector<int> G[N],ele[N];
stack<int> st;

void SCC(int u){
    low[u] = id[u] = ++ti;
    in_st[u] = true;
    st.push(u);
    for(int v : G[u]){
        if(!id[v]) SCC(v);
        if(in_st[v]) low[u] = min(low[u], low[v]);
    }
    if(low[u] == id[u]){
        num++;
        while(true){
            int now = st.top(); st.pop();
            scc_id[now] = num;
            ele[num].emplace_back(now);
            in_st[now] = false;
            if(now == u) break;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int cd, a, b, c; cin >> cd >> a >> b >> c;
        if (cd == 1) {
            G[b].emplace_back(a);
            G[c].emplace_back(a);
        } else if (cd == 2) {
            G[a].emplace_back(b);
            G[a].emplace_back(c);
        } else { //create cycle
            G[a].emplace_back(b);
            G[b].emplace_back(c);
            G[c].emplace_back(a);
        }
    }    

    for(int i = 1; i <= n; i++){
        if(!id[i]) SCC(i);
    }

    // for(int i = 1; i <= n; i++){
    //     cout << scc_id[i] << " \n"[i==n];
    // }

    cout << num << "\n";
    for(int i = num; i >= 1; i--){ //print by topological order (automatically created by performing SCC)
        cout << ele[i].size() << " ";
        sort(ele[i].begin(), ele[i].end());
        for(int e : ele[i]) 
            cout << e << " ";
        cout << "\n";
    }
    
    return 0;
}