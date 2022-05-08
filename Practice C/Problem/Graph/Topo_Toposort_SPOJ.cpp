#include <bits/stdc++.h>
using namespace std;

const int N = 1010,INF = 1e9;
using ll = long long;
using pi = pair<int,int>;

///https://www.spoj.com/problems/TOPOSORT/

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> deg(n+5);
    vector<vector<int>> G(n+1);

    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        deg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for(int i = 1; i <= n; i++) if(deg[i] == 0) pq.push(i);

    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        ans.emplace_back(u);

        for(int v : G[u]){
            if(--deg[v] == 0){
                pq.push(v);
            }
        }
    }

    if(ans.size() != n) cout << "Sandro fails.\n";
    else for(int an : ans) cout << an << " ";

    return 0;
}
