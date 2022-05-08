#include <bits/stdc++.h>
using namespace std;

//create graph that edge from u to v means u can win against v
//it can be observed that u and win against everyone if and only if it can traverse to every node in graph
//hence, we just condesation graph and check if any node can do that
//create fake node to save up memory
//https://beta.programming.in.th/tasks/o62_may11_exam

const int N = 3e6+10;

int low[N],id[N],ti,num,scc_id[N],n,K,in_deg[N];
vector<int> G[N];
stack<int> st;
bool in_st[N];

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
            in_st[now] = false;
            if(now == u) break;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1;  i <= n; i++){
        for(int j = 1; j <= K; j++){
            char c; cin >> c;
            if(c-'0' == 1) G[i].emplace_back(n+j); //create edge from i to fake node j-th
            else G[n+j].emplace_back(i); //create edge from j-th fake node to i
        }
    }

    for(int i = 1; i <= n; i++){ //there is no need to go through fake node that can't visit by any real node
        if(!id[i]) SCC(i);
    }

    for(int i = 1 ; i <= n+K; i++){
        if(id[i] == 0) continue; //just skip those fake node that aren't visited
        for(int v : G[i]){
            if(scc_id[v] != scc_id[i]){
                in_deg[scc_id[v]]++;
            }
        }
    }

    /*for(int i = 1; i <= n; i++){
        cout << scc_id[i] << " " << in_deg[scc_id[i]] << "\n";
    }*/

    int res = -1;
    for(int i = 1; i <= n; i++){
        if(in_deg[scc_id[i]] == 0){
            if(res == -1) res = scc_id[i];
            else if(res != scc_id[i]){ res = -1; break; } //node that can traverse to every node must have in deg = 0 and there must be only one
        }
    }

    if(res == -1){
        cout << "-1\n";
    }else{
        for(int i = 1; i <= n; i++) if(scc_id[i] == res) cout << i << " ";
        cout << "\n";
    }
    return 0;
}