#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;
using ll = long long;
using pi = pair<int,int>;

int n,m,want[N],pa[N],dep[N],num_cmp;
vector<pi> point;
vector<int> mem[N];
stack<int> st;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int l,r; cin >> l >> r;
        point.emplace_back(l, i);
        point.emplace_back(r, i);
    }
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        want[x] = 1;
    }
    sort(point.begin(), point.end());

    for(int i = 0; i < 2*n; i++){ ///create graph
        auto [pos, idx] = point[i];
        if(!st.empty() and st.top() == idx){
            st.pop();
        }else{
            if(st.empty()){
                num_cmp++;
            }else{
                pa[idx] = st.top();
                dep[idx] = dep[st.top()]+1;
            }
            if(want[idx]){
                mem[num_cmp].emplace_back(idx);
            }
            st.push(idx);
        }
    }
    assert(st.empty());
    if(DEBUG){
        for(int i = 1; i <= n; i++){
            cout << pa[i] << " \n"[i==n];
        }
    }

    vector<int> result;
    for(int i = 1; i <= num_cmp; i++){ ///Find lowest common ancestor of each component
        if(mem[i].empty()) continue;
        int u = mem[i][0];
        for(int j = 1; j < mem[i].size(); j++){
            int v = mem[i][j];
            //cout << "LCA of " << u << " " << v << " = ";
            if(dep[v] > dep[u]) swap(u, v);
            while(dep[u] > dep[v]) u = pa[u];
            if(u != v){
                while(pa[u] != pa[v]) u = pa[u], v = pa[v];
                u = pa[u];
            }
            //cout << u << "\n";
        }
        result.emplace_back(u);
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int res : result) cout << res << " ";
    cout << "\n";
    return 0;
}
