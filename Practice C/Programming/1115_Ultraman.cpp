#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+100;
int p[N],rnk[N],x[N],y[N],n,K;
vector<tuple<int,int,int>> edges;
vector<int> ans;
int fi(int x){
    if(p[x] == x) return x;
    return p[x]=fi(p[x]);
}
bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u!=v){
        if(rnk[u] < rnk[v])
            swap(u,v);
        p[v] = u;
        if(rnk[u] == rnk[v])
            rnk[u]++;
        return true;
    }
    return false;
}
main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        p[i] = i;
        cin >> x[i] >> y[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            edges.emplace_back((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]), i, j);
        }
    }
    sort(edges.begin(), edges.end());
    for(int i=0; i<edges.size(); i++){
        int d,u,v;
        tie(d,u,v) = edges[i];
        if(uni(u,v)){
            ans.emplace_back(d);
        }
    }
    for(int i=0; i<K-1; i++)
        ans.pop_back();
    cout << ans.back();
}
