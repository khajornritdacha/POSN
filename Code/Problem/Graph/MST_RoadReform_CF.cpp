#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

///https://codeforces.com/contest/1468/problem/J

int pa[N];

int fi(int x){
    return pa[x] = (pa[x] == x) ? x : fi(pa[x]);
}

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v) return false;
    pa[u] = v;
    return true;
}

void test_case(){
    long long ans = 0,n,m,K, mx = 0;
    cin >> n >> m >> K;

    vector<tuple<int,int,int>> edge;
    vector<bool> use(m+1);
    for(int i = 1; i <= n; i++){
        pa[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < m; i++){
        auto [w, u, v] = edge[i];
        if(uni(u, v)){
            use[i] = true;
            if(w > K){
                ans += w-K;
            }
            mx = w;
        }
    }

    //cout << "MX : " << mx << " " << ans << "\n";
    if(ans){
        cout << ans << "\n";
        return;
    }

    ans = K-mx;
    for(int i = 0; i < m; i++){
        if(use[i]) continue;
        ans = min(ans, abs(K-get<0>(edge[i])));
    }
    cout << ans << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
