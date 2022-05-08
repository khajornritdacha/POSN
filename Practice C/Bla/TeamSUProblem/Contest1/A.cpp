#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int n,m,ansa,ansb;
bool adj[500][750],go[500][750],g[500][750];
vector<int> rail[500],road[500];
priority_queue<pi,vector<pi>,greater<pi>> pq;
main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u][v]=true;
        adj[v][u]=true;
        rail[u].emplace_back(v);
        rail[v].emplace_back(u);
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(!adj[i][j]){
                //cout << i << " " << j << "\n";
                road[j].emplace_back(i);
                road[i].emplace_back(j);
            }
        }
    }
    pq.emplace(0,1);
    while(!pq.empty()){
        auto [t,u]=pq.top();
        pq.pop();
        if(u==n){
            ansa=t;
            break;
        }
        for(auto v:rail[u]){
            if(!go[v][t+1]&&t+1<n+10){
                go[v][t+1]=true;
                pq.emplace(t+1,v);
            }
        }
    }
    while(!pq.empty())
        pq.pop();
    pq.emplace(0,1);
    while(!pq.empty()){
        auto [t,u]=pq.top();
        pq.pop();
        if(u==n){
            //cout << t << "\n";
            ansb=t;
            break;
        }
        for(auto v:road[u]){
            if(!g[v][t+1]&&t+1<n+10){
                g[v][t+1]=true;
                pq.emplace(t+1,v);
            }
        }
    }
    //cout << ansa << " " << ansb << "\n";
    if(ansa==0||ansb==0)
        cout << "-1";
    else
        cout << max(ansa,ansb);
}
