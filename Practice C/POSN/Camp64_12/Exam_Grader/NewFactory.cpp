#include<bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;
vector<pi> vec[1010];
int V,E,dis[1010];
priority_queue<pi, vector<pi>, greater<pi>> pq;

main(){
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }

    for(int i=1; i<V; i++)
        dis[i] = 1e9;
    pq.emplace(0, 0);
    while(!pq.empty()){
        int wa,u;
        tie(wa, u) = pq.top();
        pq.pop();

        for(int i=0; i<vec[u].size(); i++){
            int v,w;
            tie(v, w) = vec[u][i];
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
                pq.emplace(dis[v], v);
            }
        }
    }

    for(int i=0; i<V; i++){
        cout << (char)(i+'A') << "->" << dis[i] << "\n";
    }
}
