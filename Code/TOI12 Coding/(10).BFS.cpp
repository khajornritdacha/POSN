#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool visited[100005];
vector<int> G[100005], BFSPath;

void BFS(int st){
    queue<int> q;
    q.push(st);
    visited[st] = true;
    while(!q.empty()){
        int u = q.front();
        BFSPath.push_back(u);
        q.pop();
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
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
            BFS(i);
    }
    printf("BFS Path:");
    for(int i = 0; i < BFSPath.size(); ++i){
        printf(" %d", BFSPath[i]);
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

