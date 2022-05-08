#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
int V,E;
vector<pi> vec[N];
priority_queue<pi, vector<pi>, greater<pi>> pq;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
    }
    vector<int> dis(V+1, 1e18);
    pq.emplace(0, 1);
    dis[1] = 0;
    while(pq.size()){
        auto[wa, u] = pq.top();
        pq.pop();
        if(dis[u] != wa) continue;
        for(auto [v, w] : vec[u]){
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
                pq.emplace(dis[v], v);
            }
        }
    }

    for(int i=1; i<=V; i++)
        cout << dis[i] << " ";
}
