#include<bits/stdc++.h>
using namespace std;
int ans, color[105],V,E;
vector<int> vec[105];
bool cd;
void dfs(int u, int p, int c){
    if(color[u]!=0){
        if(c!=color[u]){
            cd=1;
        }
        return;
    }
    color[u]=c;
    for(auto v : vec[u]){
        if(v==p) continue;
        dfs(v, u, (c==1) ? 2 : 1);
    }
}
main(){
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    for(int i=1; i<=V; i++){
        if(!color[i]){
            cd=0;
            dfs(i,0,1);
            if(cd) ans++;
        }
    }
    if((V-ans)%2==0) cout << ans;
    else cout << ans+1;
}
