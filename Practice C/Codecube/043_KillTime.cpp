#include<bits/stdc++.h>
using namespace std;

const int N = 3e2+10;
using tu = tuple<int,int,int>;
int V,E,K,S,T,dis[N][2010];
vector<tu> vec[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> K >> S >> T;
    for(int i=1; i<=E; i++){
        int u,v,c,w;
        cin >> u >> v >> c >> w;
        vec[u].emplace_back(v, c, w);
        vec[v].emplace_back(u, c, w);
    }
    for(int i=0; i<=K; i++) for(int j=0; j<=V; j++) dis[j][i] = -2e9;
    dis[S][0] = 0;
    for(int i=0; i<=K; i++){
        for(int u=1; u<=V; u++){
            if(dis[u][i] == -2e9) continue;
            for(auto [v,c,w] : vec[u]){
                if(i+w > K) continue;
                if(dis[u][i]+c > dis[v][i+w]){
                    dis[v][i+w] = dis[u][i]+c;
                }
            }
        }
    }
    int ans = -2e9;
    for(int i=0; i<=K; i++)
        ans = max(ans, dis[T][i]);
    if(ans == -2e9)
        cout << "Impossible";
    else
        cout << ans;
    cout << "\n";
}
