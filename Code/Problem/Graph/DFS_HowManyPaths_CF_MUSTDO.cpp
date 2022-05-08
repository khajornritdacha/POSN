#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

vector<vector<int>> g;
int V,E;
set<int> ss[2];

void dfs(int u, vector<int> &color, bool code){
    color[u] = 1;
    for(int v : g[u]){
        if(color[v] == 0){
            dfs(v, color, code);
        }else if(code){ ///categorized nodes into 2 group 1.gray(cycle) 2.black(more than 1 possible way)
            ss[color[v]-1].insert(v);
        }
    }
    color[u] = 2;
}


void test_case(){
    cin >> V >> E;
    g.clear(); g.resize(V+1);
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    for(int i=0; i<2; i++)
        ss[i] = set<int>();
    vector<int> color(V+1, 0);
    dfs(1, color, true);

    vector<vector<int>> cc(2, vector<int>(V+1, 0));
    for(int i=0; i<2; i++){
        for(int s : ss[i]){
            dfs(s, cc[i], false); ///nodes that are reachable from any node in that category will be grouped in the same type.
        }
    }

    for(int i=1; i<=V; i++){
        int res = 0;
        if(color[i]){
            res = 1;
            if(cc[0][i])
                res = -1;
            else if(cc[1][i])
                res = 2;
        }
        cout << res << " ";
    }
    cout << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
