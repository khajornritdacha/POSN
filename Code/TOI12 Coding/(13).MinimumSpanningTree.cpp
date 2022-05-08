#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class EDGE{
public:
    int u, v, w;
    EDGE(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<EDGE> edge;
int G[100005];
bool byW(const EDGE &A, const EDGE &B){
    return A.w < B.w;
}

int head[100005];

int findH(int a){
    if(head[a] == a)
        return a;
    else
        return head[a] = findH(head[a]);
}

int main(){
    int V, E;
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge.push_back(EDGE(u, v, w));
    }
    sort(edge.begin(), edge.end(), byW);
    for(int i = 1; i <= V; ++i)
        head[i] = i;
    int MST = 0;
    for(int i = 0; i < edge.size(); ++i){
        int hU = findH(edge[i].u);
        int hV = findH(edge[i].v);
        if(hU != hV){
            MST+=edge[i].w;
            head[hU] = head[hV];
        }
    }
    printf("Minimum Spanning Tree Value is %d.", MST);
    return 0;
}
/*
5
7
1 2 4
2 3 2
1 3 4
1 4 6
3 4 8
1 5 6
4 5 9
*/
