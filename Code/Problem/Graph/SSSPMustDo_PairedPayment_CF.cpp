#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int W = 55;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
int V,E,dis[N][W];
vector<pi> vec[N];
priority_queue<tu, vector<tu>, greater<tu>> pq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
    }
    for(int i=1; i<=V; i++) for(int j=0; j<=50; j++) dis[i][j] = 1e9;
    dis[1][0] = 0;
    pq.emplace(0, 1, 0);
    while(!pq.empty()){
        auto [d, u, was] = pq.top();
        pq.pop();
        for(auto [v,w] : vec[u]){
            if(was == 0){
                if(dis[u][0] < dis[v][w]){
                    dis[v][w] = dis[u][0];
                    pq.emplace(dis[v][w], v, w);
                }
            }else{
                if(d+(was + w)*(was + w) < dis[v][0]){
                    dis[v][0] = d+(was+w)*(was+w);
                    pq.emplace(dis[v][0], v, 0);
                }
            }
        }
    }
    for(int i=1; i<=V; i++){
        if(dis[i][0] == 1e9) dis[i][0] = -1;
        cout << dis[i][0] << " ";
    }
}
///https://codeforces.com/problemset/problem/1486/E
