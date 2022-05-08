#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
using tu=tuple<int,int,int>;
int t;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        int n,m,s,e,p;
        int ans=-1;
        cin >> n >> m >> s >> e >> p;
        vector<int> dis(n+1,1e9),dit(n+1,1e9);
        vector<pi> vec[n+1],vecc[n+1];
        vector<tu> edge;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        dis[s]=0;
        dit[e]=0;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            vec[u].emplace_back(v,w);
            vecc[v].emplace_back(u,w);
            edge.emplace_back(u,v,w);
        }
        pq.emplace(0,s);
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto[v,w]:vec[u]){
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    pq.emplace(dis[v],v);
                }
            }
        }
        pq.emplace(0,e);
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto[v,w]:vecc[u]){
                if(dit[u]+w<dit[v]){
                    dit[v]=dit[u]+w;
                    pq.emplace(dit[v],v);
                }
            }
        }
        for(auto[u,v,w]:edge){
            if(dis[u]!=1e9&&dit[v]!=1e9){
               if(dis[u]+dit[v]+w<=p) ans=max(ans,w);
            }
            if(dis[u]!=1e9&&dit[v]!=1e9){
                if(dis[u]+dit[v]+w<=p) ans=max(ans,w);
            }
        }
        if(dis[e]==1e9) cout << "-1\n";
        else cout << ans << "\n";
    }
}
