#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
typedef tuple<int,int,int> tu;
typedef pair<int,int> pi;
int n,m,K,dis[N][10];
vector<pi> vec[N];
priority_queue<tu, vector<tu>, greater<tu>> pq;
bool vi[N][10];
main(){
    cin >> n >> m >> K;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(w, v);
    }
    for(int k=0; k<=K; k++) for(int i=1; i<=n; i++) dis[i][k] = 2e9;
    dis[1][0] = 0;
    pq.emplace(0, 1, 0);
    while(!pq.empty()){
        auto [wa, u, k] = pq.top();
        pq.pop();
        if(vi[u][k])
            continue;
        vi[u][k] = true;
        for(auto [w, v] : vec[u]){
            if(w < -100){
                if(dis[u][k] < dis[v][k+1] and k+1 <= K){
                    dis[v][k+1] = dis[u][k];
                    pq.emplace(dis[v][k+1], v, k+1);
                }
            }else{
                if(dis[u][k] + max(w, 0) < dis[v][k] and !vi[v][k]){
                    dis[v][k] = dis[u][k] + max(w, 0);
                    pq.emplace(dis[v][k], v, k);
                }
            }
        }
    }
    int mn = 1e9;
    for(int i=0; i<=K; i++)
        mn = min(mn, dis[n][i]);
    if(mn == 1e9)
        mn = -1;
    cout << mn;
}
