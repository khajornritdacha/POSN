#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int V,E,a,b,c,d;
bool no[100005];
vector<pi> vec[100005];
priority_queue<ll,vector<pair<ll,ll>>,greater< pair<ll,ll>>> pq;
main(){
   // ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
    }
    cin >> a >> b >> c >> d;
    vector<ll> dis(V+1,4e18),rdis(V+1,4e18),vans(V+1,4e18);
    dis[a]=0;
    pq.emplace(0,a);
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto pp:vec[u]){
            int v=pp.first,w=pp.second;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.emplace(dis[v],v);
            }
        }
    }
    //cout << dis[a] << " " << dis[b] << " ";
    rdis[b]=0;
    pq.emplace(0,b);
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto pp:vec[u]){
            int v=pp.first,w=pp.second;
            if(rdis[u]+w<rdis[v]){
                rdis[v]=rdis[u]+w;
                pq.emplace(rdis[v],v);
            }
        }
    }
    ll dij=dis[b];
    for(int i=1;i<=V;i++){
        if(dis[i]+rdis[i]==dij){
            no[i]=true;
            //cout << i << " ";
        }
    }
    vans[c]=0;
    pq.emplace(0,c);
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto pp:vec[u]){
            int v=pp.first,w=pp.second;
            if(vans[u]+w<vans[v]&&no[v]==false){
                vans[v]=vans[u]+w;
                pq.emplace(vans[v],v);
            }
        }
    }
    if(vans[d]==4e18) cout << "-1";
    else cout << vans[d];
}
