#include<bits/stdc++.h>
#define int long long
using namespace std;
using pi=pair<int,int>;
int n,m,dis[200100];
vector<pi> vec[200100];
priority_queue<pi,vector<pi>,greater<pi>> pq;
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x==0){
            vec[0].emplace_back(0,i);
        }else if(x==1){
            vec[i].emplace_back(0,n+1);
        }
        dis[i]=1e18;
    }
    dis[n+1]=1e18;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(w,v);
        vec[v].emplace_back(w,u);
    }
    pq.emplace(0,0);
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        //cout << u << "\n";
        for(int i=0; i<vec[u].size(); i++){
            int w=vec[u][i].first;
            int v=vec[u][i].second;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.emplace(dis[v],v);
            }
        }
    }
    cout << dis[n+1];
}
