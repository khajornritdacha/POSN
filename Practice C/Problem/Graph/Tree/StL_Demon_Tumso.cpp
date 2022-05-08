#include <bits/stdc++.h>
using namespace std;

//Sack technique
//https://codeforces.com/blog/entry/67696
//https://beta.programming.in.th/tasks/tumso16_demon

const int N = 2e5+10;

int n, Q, sz[N], cnt[N], S[N];
long long ans[N], res;
vector<vector<int>> G, qq, child;

void dfs1(int u, int p){
    sz[u] = 1;
    for(int v : G[u]){
        if(v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
    return;
}

void dfs2(int u, int p, bool keep){
    int mx = -1, bc = -1;
    for(int v : G[u]){
        if(v != p and sz[v] > mx){
            mx = sz[v];
            bc = v;
        }
    }

    for(int v : G[u]){
        if(v != p and v != bc){
            dfs2(v, u, 0);
        }
    }
    if(bc != -1){
        dfs2(bc, u, 1);
        swap(child[u], child[bc]);
    }

    child[u].emplace_back(u);
    if(++cnt[S[u]] == 1){
        res += S[u];
    }

    for(int v : G[u]){
        if(v != p and v != bc){
            for(int vv : child[v]){
                child[u].emplace_back(vv);
                if(++cnt[S[vv]] == 1){
                    res += S[vv];
                }
            }
        }
    }

    for(int idx : qq[u]){
        ans[idx] = res;
    }

    if(keep == 0){
        for(int v : child[u]){
            if(--cnt[S[v]] == 0){
                res -= S[v];
            }
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;

    G.resize(n+5), qq.resize(n+5), child.resize(n+5);

    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        G[p].emplace_back(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> S[i];
    }
    for(int i = 1; i <= Q; i++){
        int u; cin >> u;
        qq[u].emplace_back(i);
    }

    dfs1(1, -1);
    dfs2(1, -1, 0);

    for(int i = 1; i <= Q; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}