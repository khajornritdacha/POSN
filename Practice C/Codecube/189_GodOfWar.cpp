#include<bits/stdc++.h>
#define int long long
using namespace std;
using pi=pair<int,int>;
priority_queue<pi,vector<pi>,greater<pi>> pq;
vector<tuple<int,int,int>> edge;
long long summ,ans;
int mx,n,m,s,t,bt[100100],wei[100100];
vector<pair<int,int>> vec[100100];
bitset<100100>visit;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s >> t;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
        edge.emplace_back(u,v,w);
        summ+=w;
    }
    vector<int> dis(n+1,2e18);
    dis[s]=0;
    pq.emplace(0,s);
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        visit[u]=true;
        for(auto [v,w]:vec[u]){
            if(!visit[v]&&dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                bt[v]=u;
                wei[v]=w;
                pq.emplace(dis[v],v);
            }
        }
    }
    vector<int> dit(n+1,2e18);
    dit[t]=0;
    pq.emplace(0,t);
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto [v,w]:vec[u]){
            if(dit[u]+w<dit[v]){
                dit[v]=dit[u]+w;
                bt[v]=u;
                wei[v]=w;
                pq.emplace(dit[v],v);
            }
        }
    }
    for(auto [u,v,w]:edge){
        ans=max(ans,summ-dis[u]-dit[v]);
        ans=max(ans,summ-dis[v]-dit[u]);
    }
    cout << ans << "\n";
}
