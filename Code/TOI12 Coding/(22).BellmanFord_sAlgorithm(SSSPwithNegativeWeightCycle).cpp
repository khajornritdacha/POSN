#include <cstdio>
#include <vector>
#define oo 1000000000
using namespace std;
// This Algorithm take O(VE)
// This type of graph is one-way (Directed Graph)
class EDGE{
public:
    int u, v, w;
    EDGE(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int dist[100005], V, E;
vector<EDGE> edge;

bool BellmanFord_Algorithm(int start){
    for(int i = 1; i <= V; ++i)
        dist[i] = oo;
    dist[start] = 0;
    for(int i = 0; i < V-1; ++i){       // relax all E edges ***(V-1)*** times
        for(int j = 0; j < E; ++j){     // Overall O(VE)
            int u = edge[j].u, v = edge[j].v, w = edge[j].w;
            if(dist[u]+w < dist[v])
                dist[v] = dist[u]+w;    // relax
        }
    }
    // Below this is to check Negative Weight Cycle
    // by running relax all E edges again!!
    bool hasNegativeCycle = false;
    for(int j = 0; j < E; ++j){
        int u = edge[j].u, v = edge[j].v, w = edge[j].w;
        if(dist[u]+w < dist[v]){
            hasNegativeCycle = true;
            break;
        }
    }
    return hasNegativeCycle;
}

int main(){
    int start;
    printf("Enter V E: ");
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge.push_back(EDGE(u, v, w));
    }
    printf("Enter Start Node: ");
    scanf("%d", &start);
    printf("================================\n");
    int hasNegativeCycle = BellmanFord_Algorithm(start);
    if(!hasNegativeCycle){
        printf("This Graph not has Negative Weight Cycle\n");
        for(int i = 1; i <= V; ++i){
            if(dist[i] == oo)
                printf("No Path between %d and %d\n", start, i);
            else
                printf("Shortest Path from %d to %d is %d\n", start, i, dist[i]);
        }
    }
    else
        printf("This Graph has Negative Weight Cycle!!\n");
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

4 4
1 2 10
2 3 20
3 4 30
4 1 -60
1

3 3
1 2 1000
2 3 15
3 2 -42
1
*/
