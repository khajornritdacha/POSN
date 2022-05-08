#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int up[N][25],n,Q;
vector<int> vec[N];

void dfs(int u, int p){
    up[u][0] = p;
    for(int k=1; k<=20; k++){
        if(up[u][k-1] == -1)
            up[u][k] = -1;
        else
            up[u][k] = up[up[u][k-1]][k-1];
    }
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
    }
}

int cal(int u, int wa){
    for(int k=20; k>=0; k--){
        if(u != -1 and wa >= (1<<k)){
            wa -= (1<<k);
            u = up[u][k];
        }
    }
    return u;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=2; i<=n; i++){
        int p;
        cin >> p;
        vec[p].emplace_back(i);
    }
    dfs(1, -1);
    while(Q--){
        int u,k;
        cin >> u >> k;
        cout << cal(u, k) << "\n";
    }
}
