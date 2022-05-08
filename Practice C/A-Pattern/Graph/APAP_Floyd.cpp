// Find all pair shortest path with Floyd Warshall Algorithm
// Nodes are 1-indexed (The minimum index of node is 1)
#include<bits/stdc++.h>

const int MXN = 310;
using namespace std;

int V,E,q,dis[MXN][MXN];

int main(void){
    cin >> V >> E;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            dis[i][j]=1e9;
        }
    }
    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        dis[u][v]=w;
        dis[v][u]=w;
    }
    for(int i=1; i<=V; i++) dis[i][i]=0;
    for(int k=1; k<=V; k++){
        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    cin >> q;
    while(q--){
        int u,v;
        cin >> u >> v;
        cout << dis[u][v] << "\n";
    }
}
