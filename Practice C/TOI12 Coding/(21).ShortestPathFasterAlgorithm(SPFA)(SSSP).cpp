#include <cstdio>
#include <queue>
#include <vector>
#define oo 1000000000
using namespace std;
// This algorithm take average case O(V+E)
// but worst case O(VE) [least possibility to occur]
class NODE{
public:
    int v, w;
    NODE(int v, int w){
        this->v = v;
        this->w = w;
    }
};

int dist[100005], V, E;
bool inQ[100005];
vector<NODE> G[100005];

void SPFA(int start){
    for(int i = 1; i <= V; ++i)
        dist[i] = oo;
    queue<int> q;   // Store u (NowNode we interest)
    q.push(start);
    inQ[start] = true;  // Check that Node(start) is in queue
    dist[start] = 0;    // Initial Node
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inQ[u] = false; // **Important**
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].v, w = G[u][i].w;
            if(dist[u]+w < dist[v]){    // If can relax
                dist[v] = dist[u]+w;    // relax
                if(!inQ[v]){            // add to the queue
                    q.push(v);          // only if it isn't already in the queue
                    inQ[v] = true;      // **Important**
                }
            }
        }
    }
}

int main(){
    int start;
    printf("Enter V E: ");
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(NODE(v, w));
        G[v].push_back(NODE(u, w));
    }
    printf("Enter Start Node: ");
    scanf("%d", &start);
    SPFA(start);
    printf("================================\n");
    for(int i = 1; i <= V; ++i){
        if(dist[i] == oo)
            printf("No Path between %d and %d\n", start, i);
        else
            printf("Shortest Path from %d to %d is %d\n", start, i, dist[i]);
    }
    return 0;
}
/*
5 7
2 4 3
2 3 2
3 4 7
2 5 6
3 1 6
1 5 1
4 5 5
3
*/
