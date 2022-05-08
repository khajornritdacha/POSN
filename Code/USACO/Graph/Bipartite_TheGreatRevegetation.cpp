#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int V,E,ans,vi[N];
vector<pair<char,int>> vec[N];
bool ok = true;

bool dfs(int u, int c){
    if(vi[u]){
        return (vi[u] == c);
    }
    vi[u] = c;
    for(auto [code, v] : vec[u]){
        int go = c;
        if(code == 'D')
            go = (c == 1 ? 2 : 1);
        if(!dfs(v, go))
            return false;
    }
    return true;
}
void setIO(string name=""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
main(){
    setIO("revegetate");
    cin >> V >> E;
    for(int i=0; i<E; i++){
        char c;
        int u,v;
        cin >> c >> u >> v;
        vec[u].emplace_back(c, v);
        vec[v].emplace_back(c, u);
    }
    for(int i=1; i<=V; i++){
        if(!vi[i]){
            ans++;
            ok &= dfs(i, 1);
        }
    }

    if(!ok){
        cout << 0;
    }else{
        cout << 1;
        for(int i=0; i<ans; i++)
            cout << 0;
    }
}
