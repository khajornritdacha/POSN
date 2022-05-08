#include <cstdio>
#include <vector>
using namespace std;

bool visited[100005];
vector<int> G[100005], DFSPath;

void DFS(int u){
    DFSPath.push_back(u);
    visited[u] = true;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!visited[v])
            DFS(v);
    }
}

int main(){
    int V, E;
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1; i <= V; ++i){
        if(!visited[i])
            DFS(i);
    }
    printf("DFS Path:");
    for(int i = 0; i < DFSPath.size(); ++i){
        printf(" %d", DFSPath[i]);
    }
    return 0;
}
/*
7
7
1 2
1 3
2 6
2 7
7 4
3 4
3 5
*/
