#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<vector<int>> vec;
bool visit[110];
int n,m,bf,p;
void topo(int u){
    visit[u]=true;
    for(auto v : vec[u]){
        if(!visit[v]){
            topo(v);
        }
    }
    ans.push_back(u);
}
main(){
    while(cin >> n >> m && n!=0){
        vec.resize(n+1);
        for(int i=1; i<=m; i++){
            cin >> bf >> p;
            vec[p].emplace_back(bf);
        }
        for(int i=1; i<=n; i++){
            if(!visit[i])
                topo(i);
        }
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " \n"[ans.size()-1==i];
        }
        memset(visit,0,sizeof(visit));
        vec.clear();
        ans.clear();
    }
}
