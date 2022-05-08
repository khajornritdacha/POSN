#include<bits/stdc++.h>
using namespace std;
int n,m,t[100010],p[100010];
long long ans;
vector<tuple<int,int,int>> edge;
int _fi(int x){
    if(p[x]==x) return p[x];
    return p[x]=_fi(p[x]);
}
bool uni(int u, int v){
    u=_fi(u);
    v=_fi(v);
    if(u!=v){
        p[u]=v;
        return true;
    }
    return false;
}
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> t[i];
        p[i]=i;
    }
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        edge.emplace_back(t[u]+t[v],u,v);
    }
    sort(edge.rbegin(),edge.rend());
    for(auto [wei,u,v] : edge){
        if(uni(u,v))
            ans+=wei;
    }
    cout << ans;
}
