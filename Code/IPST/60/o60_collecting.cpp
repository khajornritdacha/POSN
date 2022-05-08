#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+100;
using tu = tuple<int,int,int>;
int V,E,L,st,ed,ra[N],dis[N][50];
vector<pair<int,int>> vec[N];
priority_queue<tu,vector<tu>, greater<tu>> pq;
main(){
    cin >> V >> E >> L >> st >> ed;
    for(int i=1; i<=V; i++){
        cin >> ra[i];
    }
    for(int i=1; i<=V; i++) for(int l=0; l<=L+1; l++) dis[i][l] = 1e9;
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
    }
    pq.emplace(0, st, 0);
    dis[st][0] = 0;
    while(!pq.empty()){
        auto [wa, u, cur] = pq.top();
        pq.pop();
        int go = 0;
        if(ra[u] <= L and ra[u] == cur)
            go = 1;
        for(auto [v, w] : vec[u]){
            if(dis[u][cur]+w < dis[v][cur+go]){
                //cout << "GO : " << u << " " << cur << " " << go << " " << dis[u][cur] << " -> " << v << " " << w << " " << dis[v][cur+go] << "\n";
                dis[v][cur+go] = dis[u][cur]+w;
                pq.emplace(dis[v][cur+go], v, cur+go);
            }
        }
    }
    //cout << dis[3][1] << " " << dis[2][1] << " " << dis[2][2] << "\n";
    if(dis[ed][L] == 1e9)
        cout << "-1\n";
    else
        cout << dis[ed][L] << "\n";
}
