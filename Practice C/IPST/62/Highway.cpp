#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
bool re1[N],ren[N],des[N]; //re1 := reachable from 1, ren := reachable from n in transpose graph
pi qq[N];
int n,m,Q;
vector<int> g[N],gt[N];

void dfs(int u, int p){
    re1[u] = true;
    for(int v : g[u]){
        if(v == p or re1[v] or des[v]) continue;
        dfs(v, u);
    }
}

void dfst(int u, int p){
    ren[u] = true;
    for(int v : gt[u]){
        if(v == p or ren[v] or des[v]) continue;
        dfst(v, u);
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> Q;
    for(int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        g[u].emplace_back(v);
        gt[v].emplace_back(u);
    }
    for(int i=1; i<=Q; i++){
        cin >> qq[i].first >> qq[i].second;
        if(qq[i].first == 1){
            des[qq[i].second] = true;
        }
    }

    dfs(1, -1);
    dfst(n, -1);
    stack<int> st;

    for(int i=Q; i>=1; i--){
        auto [code, u] = qq[i];
        if(code == 1){
            des[u] = false;
            for(int v : gt[u]){
                if(re1[v]){
                    dfs(u, v);
                    break;
                }
            }
            for(int v : g[u]){
                if(ren[v]){
                    dfst(u, v);
                    break;
                }
            }
        }else{
            st.push(re1[u]&ren[u]);
        }
    }

    while(!st.empty()){
        cout << st.top() << "\n";
        st.pop();
    }

    return 0;
}
