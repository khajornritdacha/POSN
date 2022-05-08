#include<bits/stdc++.h>
using namespace std;
using pi=pair<pair<int,int>,pair<int,bool>>;
int mn=1e9,N,M,F,st,ed,dis[105][105][2];
bool visit[105][105][2];
vector<vector<pair<int,int>>> vec;
vector<int> co;
priority_queue<pi,vector<pi>,greater<pi>> pq;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    co.resize(N+1);
    vec.resize(N+1);
    for(int i=1; i<=N; i++){
        cin >> co[i];
    }
    cin >> st >> ed >> F;
    cin >> M;
    for(int i=1; i<=M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=F;j++){
            dis[i][j][false]=1e9;
            dis[i][j][true]=1e9;
        }
    }
    dis[st][0][0]=0;
    pq.push({{0,st},{0,0}});
    while(!pq.empty()){
        pi temp=pq.top();
        int now=temp.first.first,u=temp.first.second,fuel=temp.second.first;
        bool used=temp.second.second;
        pq.pop();
        if(u==ed){
            if(used){
                mn=min(mn,now+((F-fuel)*co[u]));
            }else{
                mn=min(mn,now);
            }
        }
        if(visit[u][fuel][used]) continue;
        visit[u][fuel][used] = true;
        for(auto [v,w]:vec[u]){
            if(!used&&now<dis[v][F-w][true]){
                pq.push({{now,v},{F-w,true}});
                dis[v][F-w][true]=now;
            }
            for(int i=0; i+fuel<=F; i++){
                if(now+(co[u]*i)<dis[v][i+fuel-w][used]&&i+fuel>=w){
                    pq.push({{now+(co[u]*i),v},{i+fuel-w,used}});
                    dis[v][i+fuel-w][used]=now+(co[u]*i);
                }
            }
        }
    }
    cout << mn;
}
