#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;

int pa[N],V,E,col[N];
vector<int> rpa[N],adj[N];
queue<int> qq;

void setIO(string name=""){
    ios_base::sync_with_stdio(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void uni(int u, int v){
    u = pa[u], v = pa[v];
    if(rpa[u].size() < rpa[v].size()) swap(u, v);
    for(int t : rpa[v]){
        pa[t] = u;
        rpa[u].emplace_back(t);
    }
    adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
    adj[v].clear();
    if(adj[u].size() > 1)
        qq.emplace(u);
}

main(){
    setIO("fcolor");
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    for(int i=1; i<=V; i++){
        pa[i] = i;
        rpa[i].emplace_back(i);
        if(adj[i].size() > 1)
            qq.push(i);
    }
    while(!qq.empty()){
        int x = qq.front();
        if(adj[x].size() <= 1){ qq.pop(); continue; }
        int a = adj[x].back(); adj[x].pop_back();
        if(pa[a] == pa[adj[x].back()]) continue;
        uni(a, adj[x].back());
    }
    int co = 0;
    for(int i=1; i<=V; i++){
        if(!col[pa[i]])
            col[pa[i]] = ++co;
        cout << col[pa[i]] << "\n";
    }
}

