#include <bits/stdc++.h>
using namespace std;

const int N = 30, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int n,m;
set<int> G[N];
vector<char> ans;

void dfs(int u){
    assert(u > 0);
    ans.emplace_back(u + 'A' - 1);
    if(!G[u].empty()){
        int v = *G[u].begin();
        G[u].erase(v);
        G[v].erase(u);
        dfs(v);
    }
    return;
}

int main(void){
    cin >> m;
    for(int i = 1; i <= m; i++){
        char a,b; cin >> a >> b;
        int u = a-'A'+1, v = b-'A'+1;
        G[u].insert(v);
        G[v].insert(u);
        n = max({n, u, v});
    }

    int odd = 0, st = -1;
    for(int i = 1; i <= n; i++){
        if(G[i].size() % 2){
            odd++, st = i;
        }
    }

    if(odd == 0) dfs(1); //euler circuit
    else if(odd == 2) dfs(st); //euler path
    else assert(0);

    for(char an : ans) cout << an << " ";
    cout << "\n";

    return 0;
}