#include<bits/stdc++.h>
using namespace std;
using tu=tuple<long long, long long, long long>;
using pi=pair<long long, long long>;
int V,st,ed,E;
queue<tu> pq;
vector<vector<pi>> vec;
vector<pi> chua;
vector<vector<long long>> dis;
bool visit[2010][2010];

main(){
   ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> V >> st >> ed >> E;
   vec.resize(V+1);
   dis.resize(V+1);
   for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
   }
   for(int i=0; i<V; i++){
        dis[i].resize(V+2,1e18);
   }
   dis[st][0]=0;
   pq.emplace(0,st,0);
   while(!pq.empty()){
        long long now,u,t;
        tie(now,u,t) = pq.front();
        pq.pop();
        if(visit[u][t]) continue;
        visit[u][t]=true;
        for(int i=0; i<vec[u].size(); i++){
            long long v,w;
            v=vec[u][i].first;
            w=vec[u][i].second;
            if(t<=V&&!visit[v][t+1]&&dis[u][t]+w<dis[v][t+1]){
                dis[v][t+1]=dis[u][t]+w;
                pq.emplace(dis[v][t+1],v,t+1);
            }
        }
   }
   long long pre=1e18,cd;
   for(int i=0; i<=V+1; i++){
        if(dis[ed][i]!=1e18){
            cd=i;
            break;
        }
   }
   for(int i=cd; i<=V+1; i++){
        if(dis[ed][i]<pre){
            chua.emplace_back(dis[ed][i],i-1);
            pre=dis[ed][i];
        }
   }
   int num;
   cin >> num;
   while(num--){
        long long time,ans=1e18;
        cin >> time;
        for(int i=0; i<chua.size(); i++){
            ans=min(chua[i].first+(chua[i].second*time),ans);
        }
        cout << ans << "\n";
   }
}

/*
8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3
4
0 10 2 30
*/
