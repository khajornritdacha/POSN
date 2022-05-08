#include <cstdio>
#include <queue>
#include <vector>
#define oo 1000000000
using namespace std;
// This Algorithm take O(VlogE)
class NODE{
public:
    int v, w;
    NODE(int v, int w){
        this->v = v;
        this->w = w;
    }
};

int dist[100005], V, E;
vector<NODE> G[100005];

struct cmp{
    bool operator() (const pair<int, int> &A, const pair<int, int> &B){
        return !(A.second < B.second);
    }
};

void Dijkstra_Algorithm(int start){
    for(int i = 1; i <= V; ++i)
        dist[i] = oo;
    //      Store u(NowNode) SumWeight(From Start Node)
    //                   v    v        Compare by less SumWeight come first
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    pq.push(make_pair(start, 0));
    dist[start] = 0;    // Initial Node
    while(!pq.empty()){
        int u = pq.top().first, d = pq.top().second;
        pq.pop();
        if(d > dist[u]) // Very important
            continue;
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].v, w = G[u][i].w;
            if(dist[u]+w < dist[v]){    // Relax All v next to u if can!!
                dist[v] = dist[u]+w;
                pq.push(make_pair(v, dist[v]));
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
    Dijkstra_Algorithm(start);
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
