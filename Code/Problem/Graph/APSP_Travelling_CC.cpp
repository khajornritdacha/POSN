#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e2+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int V,E,K,sp[N],adj[N][N],dis[N][(1<<16)];
vector<pi> vec[N];
priority_queue<tu, vector<tu>, greater<tu>> pq;

///CR: PIIMUU
//https://beta.programming.in.th/tasks/codecube_051

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> K;
    for(int i=0; i<=V; i++){
        for(int j=0; j<=V; j++){
            adj[i][j] = 1e9;
        }
    }
    for(int i=1; i<=K; i++){
        cin >> sp[i];
    }
    K++;
    sp[K] = V;
    for(int k=0; k<=K; k++) for(int i=0; i<(1<<(K)); i++) dis[k][i] = 1e9;
    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }
    for(int k=1; k<=V; k++){
        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    for(int k=0; k<=K; k++){
        vec[0].emplace_back(k, adj[1][sp[k]]);
        vec[k].emplace_back(0, adj[sp[k]][1]);
    }
    for(int i=1; i<=K; i++){
        for(int j=1; j<=K; j++){
            vec[i].emplace_back(j, adj[sp[i]][sp[j]]);
        }
    }
    dis[0][0] = 0;
    pq.emplace(0, 0, 0);
    while(!pq.empty()){
        auto [wa, u, now] = pq.top();
        pq.pop();
        for(auto [v,w] : vec[u]){
            int go = now;
            if(v != 0)
                go |= (1<<(v-1));
            if(dis[u][now]+w < dis[v][go]){
                dis[v][go] = dis[u][now]+w;
                pq.emplace(dis[v][go], v, go);
            }
        }
    }
    cout << dis[K][(1<<K)-1];
}