#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
vector<tuple<ll,ll,ll>> ed1,edge;
vector<pair<int,int>> vec[100100];
int p[100100],par[100100],rnk[100100],n,m,Q,k;
long long mst,mx,wei[100100];
int _fi(int x){
    if(p[x]==x) return x;
    return p[x]=_fi(p[x]);
}
void dfs(int u, int p){
    //cout << u << " ";
    for(int i=0; i<vec[u].size(); i++){
        long long v=vec[u][i].first;
        long long w=vec[u][i].second;
        if(v==p) continue;
        par[v]=u;
        rnk[v]=rnk[u]+1;
        wei[v]=w;
        //cout << v << " ";
        dfs(v,u);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    edge.emplace_back(0,0,0);
    for(int i=0; i<m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        ed1.emplace_back(w,u,v);
        edge.emplace_back(u,v,w);
    }
    sort(ed1.begin(),ed1.end());
    for(int i=1; i<=n; i++){
        p[i]=i;
    }
    for(int i=0; i<m; i++){
        long long u,v,w;
        tie(w,u,v)=ed1[i];
        int hu=_fi(u);
        int hv=_fi(v);
        if(hu!=hv){
            p[hu]=hv;
            mst+=w;
            vec[u].emplace_back(v,w);
            vec[v].emplace_back(u,w);
        }
    }
    dfs(1,0);
    cin >> Q;
    for(int oo=1; oo<=Q; oo++){
        cin >> k;
        mx=0;
        //auto [u,v,w]=edge[k];
        long long u,v,w;
        tie(u,v,w)=edge[k];
        if(rnk[v]>rnk[u])
            swap(u,v);
        if(par[u]==par[v]){
            mx=max(mx,wei[u]);
            mx=max(mx,wei[v]);
        }else{
            while(rnk[u]>rnk[v]){
                mx=max(mx,wei[u]);
                u=par[u];
            }
            while(u!=v){
                mx=max(mx,wei[u]);
                mx=max(mx,wei[v]);
                v=par[v];
                u=par[u];
            }

        }
        cout << mst-mx+w << "\n";
    }
}
