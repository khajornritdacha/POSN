#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

using ll = long long;
using pi = pair<ll, ll>;

//https://codeforces.com/contest/938/problem/D

int V, E;
long long arr[N], dis[N];
vector<pi> G[N];
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main(void){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        ll u, v, w; cin >> u >> v >> w;
        w *= 2;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    for(int i = 1; i <= V; i++){
        cin >> arr[i];
        dis[i] = arr[i];
        pq.emplace(dis[i], i);
    }

    while(!pq.empty()){
        auto [wa, u] = pq.top(); pq.pop();
        if(wa != dis[u]) continue;

        for(auto [v, w] : G[u]){
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
            }
        }
    }

    for(int i = 1; i <= V; i++) cout << dis[i] << " ";
    cout << "\n";



    return 0;
}