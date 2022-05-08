#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using lb = long double;
using ll = long long;
using pi = pair<ll,ll>;
using tu = tuple<int,int,int>;

int V,E,st,ed;
priority_queue<pi, vector<pi>, greater<pi>> pq;
vector<pi> vec[N];
vector<int> bt[N];
///https://beta.programming.in.th/tasks/tumso18_zombieland
void dij(vector<ll> &dis, bool code = 0){
    while(!pq.empty()){
        auto [wa, u] = pq.top(); pq.pop();
        if(dis[u] != wa) continue;
        for(auto [v, w] : vec[u]){
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
                pq.emplace(dis[v], v);
                if(code)
                    bt[v].clear(); bt[v].emplace_back(u);
            }else if(code and dis[u]+w == dis[v]){
                bt[v].emplace_back(u);
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> st >> ed;
    vector<ll> dis(V+1, 1e18), mn(V+1, 1e18);
    for(int i=1; i<=E; i++){
        int u,v,w; cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }

    dis[st] = 0;
    pq.emplace(0, st);
    dij(dis, 1);

    queue<int> qq;
    qq.emplace(ed);
    while(!qq.empty()){
        int u = qq.front(); qq.pop();
        if(mn[u] == 0) continue;
        //cout << u << " ";
        mn[u] = 0;
        pq.emplace(0, u);
        for(int v : bt[u]){
            qq.emplace(v);
        }
    }

    /*cout << "MN : ";
    for(int i=1; i<=V; i++){
        cout << mn[i] << " \n"[i==V];
    }*/

    dij(mn);
    int Q;
    cin >> Q;
    while(Q--){
        int u; cin >> u;
        cout << mn[u] << "\n";
    }
}
