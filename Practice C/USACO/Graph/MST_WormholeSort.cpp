#include<bits/stdc++.h>
using namespace std;

void setIO(string);
int fi(int);
bool uni(int, int);

struct DATA{
    int u,v,w;
    DATA(int x, int y, int z){
        u = x;
        v = y;
        w = z;
    }
    bool operator<(const DATA &tmp){
        return w > tmp.w;
    }
};

const int N = 1e5+10;
int V,E,a[N],ans = 1e9,p[N];
bool ok = true;
vector<DATA> edge;
vector<pair<int,int>> vec[N];


main(){
    setIO("wormsort");
    cin >> V >> E;
    for(int i=1; i<=V; i++){
        cin >> a[i];
        p[i] = i;
        if(a[i] < a[i-1]){
            ok = false;
        }
    }
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        DATA tmp(u, v, w);
        edge.emplace_back(tmp);
    }
    if(ok) { cout << "-1"; return 0; }

    sort(edge.begin(), edge.end());
    for(int i=0; i<edge.size(); i++){
        //cout << edge[i].w << " " << edge[i].u << " " << edge[i].v << "\n";
        if(uni(edge[i].u, edge[i].v)){
            vec[edge[i].u].emplace_back(edge[i].w, edge[i].v);
            vec[edge[i].v].emplace_back(edge[i].w, edge[i].u);
        }
    }
    for(int i=1; i<=V; i++){
        if(a[i] == i and vec[i].size() <= 1) continue;
        for(auto [w, v] : vec[i]){
            if(a[v] == v and vec[v].size() <= 1) continue;
            ans = min(ans, w);
        }
    }
    cout << ans << "\n";
}

void setIO(string name=""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int fi(int x){
    if(p[x] == x) return x;
    return p[x] = fi(p[x]);
}

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u != v){
        p[v] = p[u];
        return true;
    }
    return false;
}
