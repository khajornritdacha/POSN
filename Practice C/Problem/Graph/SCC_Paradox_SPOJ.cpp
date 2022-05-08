#include <bits/stdc++.h>
using namespace std;

const int N = 210, INF = 1e9;
using ll = long long;
using pi = pair<int,int>;

//2Sat
//https://www.spoj.com/problems/PARADOX/

int n, num, scc_id[N];
bool vi[N];
vector<int> G[N],rG[N];
stack<int> st;

void dfs1(int u){
    vi[u] = true;
    for(int v : G[u]) if(!vi[v]) dfs1(v);
    st.push(u);
}

void dfs2(int u){
    vi[u] = false;
    scc_id[u] = num;
    for(int v : rG[u]) if(vi[v]) dfs2(v);
}

void test_case(){
    cin >> n;
    if(n == 0) exit(0);

    for(int i = 1; i <= n; i++){
        int v;
        string op;
        cin >> v >> op;
        if(op == "false"){
            G[i].emplace_back(v+n); //if i is true then v is false
            G[i+n].emplace_back(v); //if i is false then v is true
        } else {
            G[i].emplace_back(v); //if i is true then v is true
            G[i+n].emplace_back(v+n); //if i is false then v is false
        }
    }

    for(int i = 1; i <= 2*n; i++){
        for(int v : G[i]){
            rG[v].emplace_back(i);
        }
    }

    for(int i = 1; i <= 2*n; i++) if(!vi[i]) dfs1(i);

    num = 0;
    while(!st.empty()){ //find SCC with Kosaraju
        int u = st.top(); st.pop();
        if(vi[u]){
            num++;
            dfs2(u);
        }
    }

    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(scc_id[i] == scc_id[i+n]){
            ok = false;
        }
    }

    if(!ok) cout << "PARADOX\n";
    else cout << "NOT PARADOX\n";

    for(int i = 0; i <= 2*n; i++){
        scc_id[i] = 0;
        G[i].clear(); rG[i].clear();
    }

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        test_case();
    }

    return 0;
}