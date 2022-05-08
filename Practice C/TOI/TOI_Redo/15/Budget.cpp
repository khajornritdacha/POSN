#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int V,E,P,pa[N];
vector<pi> promo;
vector<tu> edge;

int fi(int x){
    return pa[x] = (x == pa[x]) ? x : fi(pa[x]);
}

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u != v){
        pa[u] = v;
        return true;
    }
    return false;
}



int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i = 1; i <= V; i++) pa[i] = i;
    for(int i = 1; i <= E; i++){
        int u,v,w,c; cin >> u >> v >> w >> c;
        if(c == 1) uni(u,v);
        else edge.emplace_back(w, u, v);
    }
    cin >> P;
    for(int i = 1; i <= P; i++){
        int l,p; cin >> l >> p;
        promo.emplace_back(l, p);
    }
    sort(promo.begin(), promo.end());

    for(int i = P-1; i >= 1; i--){
        if(promo[i].second <= promo[i-1].second){
            promo[i-1] = promo[i];
        }
    }

    sort(edge.begin(), edge.end());
    ll ans = 0;
    for(auto [w, u, v] : edge){
        if(uni(u, v)){
            int k = lower_bound(promo.begin(), promo.end(), pi(w, -1e9))-promo.begin();
            assert(k >= 0 and k < P);
            ans += promo[k].second;
        }
    }

    cout << ans << "\n";
    return 0;
}
