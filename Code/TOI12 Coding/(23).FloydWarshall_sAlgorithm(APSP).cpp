#include <cstdio>
#include <algorithm>
#define oo 1000000000
using namespace std;
// This Algorithm take O(V^3)
// to find All-Pairs Shortest Path (all SP from u to v)
// This graph keep in Adjacency Matrix

int V, E;
int dp[105][105];

void FloydWarshall_Algorithm(){
    for(int k = 1; k <= V; ++k){    // remember this loop order k->i->j
        for(int i = 1; i <= V; ++i){
            for(int j = 1; j <= V; ++j){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);    // Dynamic Thinking
                // Find min between (i->j) and (i->k)then(k->j)
            }
        }
    }
    return;
}

int main(){
    printf("Enter V E: ");
    scanf("%d%d", &V, &E);
    // Initial DP[i][j] = INFINITY for all i->j
    for(int i = 1; i <= V; ++i){
        for(int j = 1; j <= V; ++j)
            dp[i][j] = oo;
    }
    for(int i = 0; i < E; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if(dp[u][v] == oo){
            dp[u][v] = 0;
            dp[v][u] = 0;
        }
        dp[u][v]+=w;
        dp[v][u]+=w;
    }
    FloydWarshall_Algorithm();
    printf("================================\n");
    for(int i = 1; i <= V; ++i){
        for(int j = 1; j <= V; ++j){
            if(dp[i][j] == oo)
                printf("No Path between %d and %d\n", i, j);
            else
                printf("Shortest Path from %d to %d is %d\n", i, j, dp[i][j]);
        }
        printf("\n");
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
*/
