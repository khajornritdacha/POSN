#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10,INF = 1e9;
using ll = long long;
using pi = pair<int,int>;

int dis[N],pa[N],n;
vector<int> G[N], in_path;

///https://codeforces.com/problemset/problem/1294/F
///Two of three nodes have to be the end points of diameter and the other one has the longest path from diameter

void dfs(int u){
    for(int v : G[u]){
        if(dis[u] + 1 < dis[v]){
            dis[v] = dis[u] + 1;
            pa[v] = u;
            dfs(v);
        }
    }
}

void ini(){
    for(int i = 1; i <= n; i++) dis[i] = INF;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    ini();
    dis[1] = 0;
    dfs(1);
    int S = 0;
    for(int i = 1; i <= n; i++) if(dis[i] > dis[S]) S = i;

    ini();
    dis[S] = 0;
    dfs(S);
    int T = 0;
    for(int i = 1; i <= n; i++) if(dis[i] > dis[T]) T = i;
    int ans = dis[T];

    ini();
    int u = T;
    while(u != S){
        in_path.emplace_back(u);
        dis[u] = 0;
        u = pa[u];
    }
    in_path.emplace_back(S);
    dis[S] = 0;
    
    for(int cur : in_path)
        dfs(cur);

    int mx = 0;
    dis[0] = -1;
    for(int i = 1; i <= n; i++) if(dis[i] > dis[mx] and i != S and i != T) mx = i;
    ans += dis[mx];

    cout << ans << "\n";
    cout << S << " " << T << " " << mx << "\n";

    //for(int i = 1; i <= n; i++) cout << dis[i] << " \n"[i==n];
    return 0;
}
