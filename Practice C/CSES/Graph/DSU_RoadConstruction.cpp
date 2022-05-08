#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int V,E,cmp,mx=1;
vector<int> sz,p;

int fi(int x){
    return p[x] = (p[x] == x ? x : fi(p[x]));
}
bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u != v){
        if(sz[v] > sz[u])
            swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
        mx = max(mx, sz[u]);
        return true;
    }
    return false;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> V >> E;
   sz.resize(V+1, 1);
   p.resize(V+1, 0);
   iota(p.begin(), p.end(), 0);
   cmp = V;
   for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        if(uni(u, v)){
            cmp--;
        }
        cout << cmp << " " << mx << "\n";
   }
}
