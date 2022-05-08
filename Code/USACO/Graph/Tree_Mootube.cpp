#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+10;
using pi = pair<int,int>;
int n,Q,cnt,K;
vector<pi> vec[N];

void dfs(int u, int p){
    cnt++;
    for(auto [v, w] : vec[u]){
        if(v == p) continue;
        if(w >= K)
            dfs(v, u);
    }
}
void setIO(string name=""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
main(){
    setIO("mootube");
    cin >> n >> Q;
    for(int i=1; i<n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
        vec[v].emplace_back(u, w);
    }
    while(Q--){
        int v;
        cin >> K >> v;
        cnt = 0;
        dfs(v, v);
        cout << cnt-1 << "\n";
    }
}
