#include<bits/stdc++.h>
using namespace std;

const int N = 5e2+10;
vector<bool> vi;
int V,E,cnt,mx;
vector<int> vec[N],ans;

void dfs(int u){
    if(vi[u])
        return;
    vi[u] = true;
    cnt++;
    for(int v : vec[u])
        dfs(v);
}
main(){
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
    }
    for(int i=0; i<V; i++){
        vi.assign(V+1, false);
        cnt = -1;
        dfs(i);
        if(cnt > mx){
            mx = cnt;
            ans.clear();
            ans.emplace_back(i);
        }else if(cnt == mx){
            ans.emplace_back(i);
        }
    }
    cout << mx << "\n";
    for(int an : ans){
        cout << an << " ";
    }
}
