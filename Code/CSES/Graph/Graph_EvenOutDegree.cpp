#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int ti,disc[N],V,E,cnt,deg[N];
vector<int> vec[N];
vector<pair<int,int>> ans;

void dfs(int u, int p){
    disc[u] = ti++;
    for(int v : vec[u]){
        if(v == p) continue;
        if(disc[v] == -1){
            cnt++;
            dfs(v, u);
            if(deg[v]%2){
                deg[v]++;
                ans.emplace_back(v, u);
            }else{
                deg[u]++;
                ans.emplace_back(u, v);
            }
        }else{
            if(disc[v] < disc[u]){ /// back edge
                cnt++;
                ans.emplace_back(u, v);
                deg[u]++;
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(disc, -1, sizeof(disc));
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }

    for(int i=1; i<=V; i++){
        //cout << "DISC " << i << " = " << disc[i] << "\n";
        if(disc[i] == -1){
            cnt = 0;
            dfs(i, -1);
            //cout << "I : " << i << " = " << cnt << "\n";
            if(cnt%2){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(auto [u, v] : ans){
        cout << u << " " << v << "\n";
    }
}
