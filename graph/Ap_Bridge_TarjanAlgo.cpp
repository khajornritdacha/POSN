///Finding Articulation point and bridge with tarjan algorithm
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
int V,E,low[N],disc[N],ti;
vector<int> arti,vec[N];
vector<pi> bridge;

void dfs(int u, int p){
    low[u] = disc[u] = ti++;
    int ch = 0;
    for(int v : vec[u]){
        if(v == p) continue;
        if(disc[v] != -1){
            ///there is back edge from u to v
            low[u] = min(low[u], disc[v]);
        }else{
            ///this is forward edge
            ch++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            ///low[v] equal to disc[u] if there is back edge from v to u -> (1)
            if(p != -1 and low[v] >= disc[u]){
                ///if lowest time that v can have is greater or equal to disc[u] -> there are no back edge from v to parent/ancestor of u
                ///so u will be articulation point
                arti.emplace_back(u);
            }
            ///operator in bridge is > while articulation point is >= because
            ///if low[v] equal to disc[u] if there is back edge from v to u, this tells us that v can traverse to u without using forward edge so this forward edge is not a bridge.
            ///while articulation point has = sign because go back to read (1), so we delete u then ancestor of u cannot traverse to v
            if(low[v] > disc[u]){
                bridge.emplace_back(u, v);
            }
        }
    }
    if(p == - 1 and ch > 1)
        arti.emplace_back(u);
}
main(){
    memset(disc, -1, sizeof(disc));
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }

    dfs(1, -1);

    cout << "Articulation Points are : ";
    for(int ar : arti)
        cout << ar << " ";
    cout << "\n";

    cout << "Bridges are : ";
    for(auto [u, v] : bridge)
        cout << "("<<u<<", "<<v<<") ";
    cout << "\n";

}

/*
12 12
1 2
1 6
1 7
1 12
6 8
6 9
2 3
2 10
10 11
3 4
4 5
5 12
*/
