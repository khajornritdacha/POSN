#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int id[N], low[N], ti, V, E, scc_id[N], scc_cnt, deg[N];
stack<int> st;
vector<pi> G[N];
vector<tu> edge;
vector<vector<int>> cmp;

void scc(int u, int p){
    id[u] = low[u] = ++ti;
    st.push(u);
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        if(!id[v]) scc(v, u);
        low[u] = min(low[u], low[v]);
    }

    if(low[u] == id[u]){
        scc_cnt++;
        vector<int> tmp;
        while(true){
            int now = st.top(); st.pop();
            scc_id[now] = scc_cnt;
            tmp.emplace_back(now);
            if(now == u) break;
        }        
        if(tmp.size() > 1) cmp.emplace_back(tmp);
    }
    
}

void dij(int start, vector<int> &dis){
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dis[start] = 0;
    pq.emplace(0, start);
    while(!pq.empty()){
        auto [wa, u] = pq.top(); pq.pop();
        if(dis[u] != wa) continue;

        for(auto [v, w] : G[u]){
            if(scc_id[u] != scc_id[v]) continue;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
            }
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> E >> V;
    for(int i = 1; i <= E; i++){
        int u, v, w; cin >> u >> v >> w;
        u++, v++;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        edge.emplace_back(w, u, v);
    }

    scc(1, -1);

    long long ans = 0;
    for(auto [w, u, v] : edge){
        if(scc_id[u] != scc_id[v]) ans += 2*w;
        else ans += w;
    }

    for(vector<int> vec : cmp){
        for(int u : vec){
            for(auto [v, w] : G[u]){
                if(scc_id[u] == scc_id[v]){
                    deg[v]++;
                }
            }
        }

        vector<int> use;
        for(int u : vec){
            if(deg[u] == 3){
                use.emplace_back(u);
            }
        }

        assert((int)use.size()%2 == 0);

        if(!use.empty()){ //find shortest path from nodes that have odd degree for creating fake parallel edge so that every nodes have even degree and become Euler circuit
            
            if(use.size() == 2){ //(0, 1)
                vector<int> dis(V+5, INF);
                dij(use[0], dis);
                ans += dis[use[1]]; 
            } else if(use.size() == 4){
                vector<vector<int>> dis(4, vector<int>(V+5, INF));
                for(int i = 0; i < 4; i++) dij(use[i], dis[i]); //(0, 1) + (2, 3), (0 ,2) + (1, 3), (0, 3) + (1, 2)
                int tmp = min({dis[0][use[1]] + dis[2][use[3]], dis[0][use[2]] + dis[1][use[3]], dis[0][use[3]] + dis[1][use[2]] });
                ans += tmp;
            } else {
                assert(0);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}