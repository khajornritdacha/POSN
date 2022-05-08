#include <bits/stdc++.h>
using namespace std;

const int N = 410, INF = 1e9;
using tu = tuple<int,int,int>;

int R,C,n, cp[N*N], l[4*N*N], r[4*N*N], id[N][N], res[4*N*N];
bool in[4*N*N];
vector<tu> edge;

//Parallel B-search

int fi(int x){ return cp[x] = (cp[x] == x) ? x : fi(cp[x]); }

bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v) return false;
    cp[v] = u;
    return true;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    n = R*C;
    for(int i = 1, cnt = 0; i <= R; i++) for(int j = 1; j <= C; j++) id[i][j] = ++cnt;

    for(int i = 1; i <= n; i++) cp[i] = i;

    for(int i = 1; i <= R; i++){
        for(int j = 1; j < C; j++){
            int w; cin >> w;
            edge.emplace_back(w, id[i][j], id[i][j+1]);
        }
        if(i != R){
            for(int j = 1; j <= C; j++){
                int w; cin >> w;
                edge.emplace_back(w, id[i][j], id[i+1][j]);
            }
        }
    }

    sort(edge.begin(), edge.end());
    vector<int> use;
    for(int i = 0; i < edge.size(); i++){
        auto [w, u, v] = edge[i];
        if(uni(u, v)){
            in[i] = true;
            use.emplace_back(i);
        } else {
            l[i] = 0, r[i] = n-1, res[i] = -1;
        }
    }

    assert(use.size() == n-1);

    bool ch = true;
    vector<vector<int>> event(n);
    while(ch){
        ch = false;

        for(int i = 0; i < edge.size(); i++){
            if(in[i]) continue;
            if(l[i] <= r[i]){
                event[(l[i] + r[i]) / 2].emplace_back(i);
                ch = true;
            }
        } 

        for(int i = 1; i <= n; i++) cp[i] = i;

        for(int i = 0; i < n-1; i++){
            auto [w, u, v] = edge[use[i]];
            uni(u, v);
            
            for(int j : event[i]){
                auto [w2, u2, v2] = edge[j];
                if(fi(u2) == fi(v2)){
                    res[j] = w2-w;
                    r[j] = i-1;
                } else {
                    l[j] = i+1;
                }
            }
            event[i].clear();
        }
    }

    int ans = INF;
    for(int i = 0; i < edge.size(); i++){
        if(in[i]) continue;
        ans = min(ans, res[i]);
        //cout << l[i] << " " << r[i] << "  " << res[i] << "\n";
    }

    cout << ans << "\n";

    return 0;
}