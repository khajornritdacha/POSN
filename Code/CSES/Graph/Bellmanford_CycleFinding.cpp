#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18, N = 5010;

ll dis[N];
int n,m,pa[N];
vector<tuple<int,int,int>> edge;
vector<int> ans;
set<int> ps[N];
bool vi[N];

bool bellmanford(){
    int neg = 0;
    for(int i = 1; i <= n; i++){
        neg = 0;
        for(auto [u, v, w] : edge){
            if(dis[u] + w < dis[v]){
                dis[v] = max(-INF, dis[u] + w);
                neg = v;
                pa[v] = u;
            }
        }
    }

    if(neg){ ///neg will be the last node that is relaxed
       int u = neg;
       for(int i = 1; i <= n; i++) u = pa[u]; ///set u = to the earliest node in cycle

       ans.emplace_back(u);
       int now = pa[u];
       while(now != u){
            ans.emplace_back(now);
            now = pa[now];
       }
       ans.emplace_back(u);
    }

    return neg;
}

int main(void){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge.emplace_back(u, v, w);
    }

    ///set base dis for every node to 0 in case of finding any negative cycle
    ///set dis(st) = 0 and others to INF in case of finding negative cycle in path from st to ed

    if(bellmanford()){
        cout << "YES\n";
        reverse(ans.begin(), ans.end());
        for(int an : ans) cout << an << " ";
        cout << "\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}

/*
7 8
1 7 -10
7 2 -5
2 3 -2
3 4 -7
3 6 -10
6 5 -100
5 2 -8
4 1 1
*/
