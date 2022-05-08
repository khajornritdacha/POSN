#include<bits/stdc++.h>
using namespace std;
int cnt,cmp,n,m;
vector<vector<int>> vec;
bool visit[50010];
void dfs(int u){
    visit[u]=true;
    for(int v : vec[u]){
        if(!visit[v])
            dfs(v);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> m && n!=0){
        vec.resize(n+1);
        cnt++;
        for(int i=1; i<=m; i++){
            int u,v;
            cin >> u >> v;
            vec[u].emplace_back(v);
            vec[v].emplace_back(u);
        }
        for(int i=1; i<=n; i++){
            if(!visit[i]){
                cmp++;
                dfs(i);
            }
        }
        cout << "Case " << cnt << ": " << cmp << "\n";
        vec.clear();
        fill(visit,visit+n+1,false);
        cmp=0;
    }
}
/*
https://www.proprog.ml/tasks/count_type/
*/
