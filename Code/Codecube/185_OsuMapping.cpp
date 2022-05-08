#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
using ll=long long;
using tu=tuple<ll,ll,ll>;
int V,E,T,st,ed;
vector<vector<bool>> visit;
vector<vector<ll>> dis;
vector<vector<pi>> vec;
priority_queue<tu,vector<tu>,greater<tu>> pq;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> T;
    cin >> st >> ed;
    vec.resize(V+1);
    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
    }
    dis.resize(V+1);
    visit.resize(V+1);
    for(int i=1; i<=V; i++){
        dis[i].resize(T+1,1e18);
        visit[i].resize(T+1,false);
    }
    dis[st][1] = 0;
    pq.emplace(0,1,st);
    while(!pq.empty()){
        int waste,t,u;
        tie(waste,t,u) = pq.top();
        pq.pop();
        if(visit[u][t])
            continue;
        visit[u][t] = true;
        for(auto[v,w]:vec[u]){
            if(dis[u][t]+w<dis[v][(t+1)%T]){
                dis[v][(t+1)%T] = dis[u][t]+w;
                pq.emplace(dis[v][(t+1)%T],(t+1)%T,v);
            }
        }
    }
    if(dis[ed][0]!=1e18)
        cout << dis[ed][0];
    else cout << "-1";
}
