#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 1e9, LOG = 30;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int n,m,scc_id[N],low[N],id[N],num,ti;
bool in_st[N];
vector<int> G[N];
stack<int> st;

void SCC(int u){
    low[u] = id[u] = ++ti;
    in_st[u] = true;
    st.push(u);
    for(int v : G[u]){
        if(!id[v]) SCC(v);
        if(in_st[v]) low[u] = min(low[u], low[v]);
    }
    if(id[u] == low[u]){
        num++;
        while(true){
            int now = st.top(); st.pop();
            in_st[now] = false;
            scc_id[now] = num;
            if(now == u) break;
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        char w1, w2; 
        int u1, u2; 
        cin >> w1 >> u1 >> w2 >> u2;
        
        G[u1 + ((w1 == '-') ? 0 : m)].emplace_back(u2 + ((w2 == '-') ? m : 0));
        G[u2 + ((w2 == '-') ? 0 : m)].emplace_back(u1 + ((w1 == '-') ? m : 0));

    }    

    // for(int i = 1; i <= 2*m; i++){
    //     cout << "GO " << i << " : ";
    //     for(int v : G[i]) cout << v << " ";
    //     cout << "\n";
    // }

    for(int i = 1; i <= 2*m; i++) if(!id[i]) SCC(i);

    // for(int i = 1; i <= 2*m; i++){
    //     cout << scc_id[i] << " ";
    // }
    // cout << "\n";

    for(int i = 1; i <= m; i++){
        if(scc_id[i] == scc_id[m+i]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for(int i = 1; i <= m; i++){
        if(scc_id[i] < scc_id[i+m]){
            cout << "+";
        } else {
            cout << "-";
        }
    }


    return 0;
}