#include<bits/stdc++.h>
using namespace std;
int V,E;
queue<int> qq;
vector<pair<int,int>> vec[10010];
vector<int> cnt(10010,0),dis(10010,1e9),in_q(10010,false);

main(){
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);///direct graph
        //vec[v].emplace_back(u,w);
    }
    dis[0]=0;
    qq.emplace(0);
    while(!qq.empty()){
        int u = qq.front();
        qq.pop();
        in_q[u]=false;
        for(auto [v,w]:vec[u]){
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                if(!in_q[v]){
                    qq.emplace(v);
                    in_q[v]=true;
                    if(++cnt[v]>=V){
                        cout << "Found neg_cycle\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Not found neg_cycle\n";
    return 0;
}
///found
/*
3 3
0 1 1000
1 2 15
2 1 -42
*/

/// not found
/*
4 4
0 1 10
1 2 20
2 3 30
3 0 -60
*/
