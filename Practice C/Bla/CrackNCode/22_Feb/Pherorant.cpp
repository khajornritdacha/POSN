#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int P, S, K, E, inserv[N], inmap[N], arr[N], dis[N], vi[N];
bool ban[N];
vector<int> G[N];

int bfs_shortestpath(const int t){
    queue<int> qq;
    if(!ban[1]){
        qq.emplace(1);
        dis[1] = 0;
    }
    while(!qq.empty()){
        int u = qq.front(); qq.pop();
        vi[u] = t;
        
        for(int v : G[u]){
            if(!ban[v] and vi[v] != t){
                vi[v] = t;
                dis[v] = dis[u] + 1;
                qq.emplace(v);
            }
        }
    }

    return (vi[K] == t) ? dis[K] : -1;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> P >> S >> K >> E;
    for(int i = 1; i <= P; i++){
        int b; cin >> b;
        inserv[b]++;
    }
    for(int i = 1; i <= E; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i = 2; i <= P; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= S; i++){
        inmap[inserv[i]] += inserv[i];
    }

    // Check number of player in map
    // for(int i = 1; i <= P; i++){
    //     cout << "In map " << i << " = " << inmap[i] << "\n";
    // }

    long long ans = 0;
    for(int i = 1; i <= P; i++){
        ban[arr[i]] ^= 1;

        if(inmap[i] <= 0) continue;

        ans += 1ll*inmap[i]*bfs_shortestpath(i);
    }

    cout << ans << "\n";

    return 0;
}