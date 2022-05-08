#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;
 
//Euler circuit
//dfs bottom up style
//dfs its child and cut edge
 
int n,m;
set<int> G[N];
vector<int> ans;
 
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }    
    
 
    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(G[i].size() % 2 != 0) ok = false;
    }
 
    if(!ok){ cout << "IMPOSSIBLE\n"; return 0; }
 
    stack<int> st;
    st.push(1);
    while(!st.empty()){
        int u = st.top();
        if(G[u].size() == 0){
            ans.emplace_back(u);
            st.pop();
        } else {
            int v = *G[u].begin();
            G[v].erase(u);
            G[u].erase(v);
            st.push(v);
        }
    }

    if(ans.size() != m+1) cout << "IMPOSSIBLE\n";
    else {
        for(int an : ans) cout << an << " ";
        cout << "\n";
    }

    return 0;
}