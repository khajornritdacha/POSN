#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using pi = pair<int,int>;

int n,m,vi[N];
bool cyc;
vector<int> G[N];
stack<int> st;

bool topo(int u){
    if(vi[u]){
        return vi[u] == 1;
    }
    vi[u] = 1;
    for(int v : G[u]) if(topo(v)) return true;
    vi[u] = 2;
    st.push(u);
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
    }    

    for(int i = 1; i <= n; i++){
        if(!vi[i]) cyc |= topo(i);
    }

    if(cyc){
        cout << "IMPOSSIBLE\n";
    }else{
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
    return 0;
}