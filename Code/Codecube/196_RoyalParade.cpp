#include<bits/stdc++.h>
#define int long long
using namespace std;

using pi = pair<int,int>;
const int N = 1e5+10;
int V,E,dis[N][3],st,ed,sf,ef;
bitset<N> chk;
vector<pi> vec[N];

void dij(int start, int cc){
    dis[start][cc] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.emplace(0, start);
    while(!pq.empty()){
        auto [wa, u] = pq.top();
        pq.pop();
        for(auto [v, w] : vec[u]){
            if(cc == 2 and chk[v]) continue;
            if(dis[u][cc] + w < dis[v][cc]){
                dis[v][cc] = dis[u][cc] + w;
                pq.emplace(dis[v][cc], v);
            }
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }

    for(int i=0; i<=V; i++) for(int j=0; j<3; j++) dis[i][j] = 1e18;

    cin >> st >> ed >> sf >> ef;
    dij(st, 0);
    dij(ed, 1);

    //cout << dis[ed][0] << "\n";

    for(int i=1; i<=V; i++){
        if(dis[i][0]+dis[i][1] == dis[ed][0]){
            chk[i] = true;
        }
    }

    dij(sf, 2);
    if(dis[ef][2] == 1e18){
        dis[ef][2] = -1;
    }
    cout << dis[ef][2];
}
