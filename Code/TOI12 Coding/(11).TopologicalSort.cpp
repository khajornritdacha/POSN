#include <cstdio>
#include <vector>
using namespace std;

bool visited[100005];
vector<int> G[100005], topoOrder;

void TOPO(int u){
    visited[u] = true;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!visited[v])
            TOPO(v);
    }
    topoOrder.push_back(u);
}

int main(){
    int V, E;
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
    }
    for(int i = 1; i <= V; ++i){
        if(!visited[i])
            TOPO(i);
    }
    printf("Topological Order:");
    for(int i = topoOrder.size()-1; i >= 0; --i){
        printf(" %d", topoOrder[i]);
    }
    return 0;
}
/*
8
9
1 2
2 3
1 3
1 4
3 4
3 5
4 6
8 7
7 1
*/

