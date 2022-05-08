#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 1e5+10, INF = 1e9;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int st = -1, n, Q, sz, cy[N], uw[N], qx[N], qs[N], id[N], h[N];
bool vi[N],inc[N];
vector<pi> G[N];

void dfc(int u, int p){
    if(vi[u]){
        st = u;
        return;
    }
    vi[u] = true;
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        dfc(v, u);

        if(st == 0) return;

        if(st != -1){
            sz++;
            //cout << u << " " << w << "\n";
            inc[u] = true;
            cy[sz] = u;
            uw[sz] = w;
            if(st == u){
                st = 0;
            }
            return;
        }
    }
}

void dfsp(int u, int p, int root){
    h[u] = root;
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        if(inc[v]) continue; //v is in cycle
        qs[v] = qs[u] ^ w;
        dfsp(v, u, root);
    }
}

int cal(int u, int hu, int hv, int v){
    int res = INF;
    if(id[hu] > id[hv]) swap(hu, hv);
    int t1 = qx[id[hv]] ^ qx[id[hu]];
    int t2 = qx[sz+1] ^ qx[id[hv]] ^ qx[id[hu]];
    res = min({res, qs[u]^t1^qs[v], qs[u]^t2^qs[v]});
    // cout << u << " " << hu << " " << v << " " << hv << "\n";
    // cout << qs[u] << " " << qs[v] << " " << res << "\n";
    return res;
}

main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dfc(1, -1);

    for(int i = 1; i <= sz/2; i++){
        swap(cy[i], cy[sz-i+1]);
        swap(uw[i], uw[sz-i+1]);
    }

    // cout << "In cycle : ";
    // for(int i = 1; i <= sz; i++){
    //     cout << cy[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 1; i <= sz; i++){
    //     cout << uw[i] << " ";
    // }
    // cout << "\n";

    for(int i = 1; i <= sz; i++){
        id[cy[i]] = i;
        dfsp(cy[i], -1, cy[i]);
    }

    for(int i = 1; i <= sz+1; i++){
        qx[i] = qx[i-1] ^ uw[i-1];
        //cout << qx[i] << " ";
    }
    //cout << "\n";

    while(Q--){
        // cout << "QUERY : ";
        int u, v; cin >> u >> v;
        int ans = cal(u, h[u], h[v], v);    
        cout << ans << "\n";
    }

    return 0;
}
