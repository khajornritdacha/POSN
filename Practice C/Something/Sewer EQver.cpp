#include<bits/stdc++.h>
using namespace std;
char x[102][102];
int visit[101][101];
int dis[101][101];
int n,m,ans,xx,yy;

void bfs(){
    int nodex=1;
    int nodey=1;
    dis[1][1]=1;
    deque<pair<int,int>> z,ll;
    z.emplace_back(nodex,nodey);
    while(z.size()!=0){
    nodex=z[0].first;
    nodey=z[0].second;
    visit[nodex][nodey]=1;
    if(x[nodex][nodey]=='R'){
        if(visit[nodex-1][nodey]==0 && nodex>=2 && nodey>=1 && (x[nodex-1][nodey]=='D' || x[nodex-1][nodey]=='B')){
            z.emplace_back(nodex-1,nodey);
            dis[nodex-1][nodey]=dis[nodex][nodey]+1;
        }
        if(visit[nodex][nodey-1]==0 && nodex>=1 && nodey>=2 && (x[nodex][nodey-1]=='R' || x[nodex][nodey-1]=='B')){
            z.emplace_back(nodex,nodey-1);
            dis[nodex][nodey-1]=dis[nodex][nodey]+1;
        }
        if(visit[nodex][nodey+1]==0 && nodey+1<=m){
            z.emplace_back(nodex,nodey+1);
            dis[nodex][nodey+1]=dis[nodex][nodey]+1;
        }
    }
    if(x[nodex][nodey]=='D'){
        if(visit[nodex-1][nodey]==0 && nodex>=2 && nodey>=1 && (x[nodex-1][nodey]=='D' || x[nodex-1][nodey]=='B')){
            z.emplace_back(nodex-1,nodey);
            dis[nodex-1][nodey]=dis[nodex][nodey]+1;
        }
        if(visit[nodex][nodey-1]==0 && nodex>=1 && nodey>=2 && (x[nodex][nodey-1]=='R' || x[nodex][nodey-1]=='B')){
            z.emplace_back(nodex,nodey-1);
            dis[nodex][nodey-1]=dis[nodex][nodey]+1;
        }
        if(visit[nodex+1][nodey]==0 && nodex+1<=n){
            z.emplace_back(nodex+1,nodey);
            dis[nodex+1][nodey]=dis[nodex][nodey]+1;
        }
    }
    if(x[nodex][nodey]=='B'){
        if(visit[nodex-1][nodey]==0 && nodex>=2 && nodey>=1 && (x[nodex-1][nodey]=='D' || x[nodex-1][nodey]=='B')){
            z.emplace_back(nodex-1,nodey);
            dis[nodex-1][nodey]=dis[nodex][nodey]+1;
        }
        if(visit[nodex][nodey-1]==0 && nodex>=1 && nodey>=2 && (x[nodex][nodey-1]=='R' || x[nodex][nodey-1]=='B')){
            z.emplace_back(nodex,nodey-1);
            dis[nodex][nodey-1]=dis[nodex][nodey]+1;
        }
        if(visit[nodex+1][nodey]==0 && nodex+1<=n){
            z.emplace_back(nodex+1,nodey);
             dis[nodex+1][nodey]=dis[nodex][nodey]+1;
        }
        if(visit[nodex][nodey+1]==0 && nodey+1<=m){
            z.emplace_back(nodex,nodey+1);
             dis[nodex][nodey+1]=dis[nodex][nodey]+1;
        }
    }
    if(x[nodex][nodey]=='N'){
        if(visit[nodex-1][nodey]==0 && nodex>=2 && nodey>=1 && (x[nodex-1][nodey]=='D' || x[nodex-1][nodey]=='B')){
            z.emplace_back(nodex-1,nodey);
            dis[nodex-1][nodey]=dis[nodex][nodey]+1;
        }
        if(visit[nodex][nodey-1]==0 && nodex>=1 && nodey>=2 && (x[nodex][nodey-1]=='R' || x[nodex][nodey-1]=='B')){
            z.emplace_back(nodex,nodey-1);
            dis[nodex][nodey-1]=dis[nodex][nodey]+1;
        }
    }
    z.pop_front();
    if(z.size()>=1){
    ll=z;
    sort(ll.begin(),ll.end());
    for(int i=0;i<ll.size()-1;i++){
        if(ll[i].first==ll[i+1].first && ll[i].second==ll[i+1].second){
                cout << dis[ll[i].first][ll[i].second] << "\n" <<  ll[i].first << " " << ll[i].second;
                return;
        }
    }
    }
    }
}

main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> x[i][j];
        }
    }
    bfs();
}
