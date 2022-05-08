#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

//https://codeforces.com/contest/600/problem/E
//mx for the list of element that appears most frequent

const int N = 1e5+10;
int cnt[N], sz[N], n, co[N];
long long res[N], ans[N];
vector<int> mx[N], ch[N], G[N];

void add(int p, int u){
    ch[p].emplace_back(u);
    if(mx[p].empty()){
        mx[p].emplace_back(u);
        res[p] += co[u];
    } else {
        if(cnt[co[u]] + 1 > cnt[co[mx[p].front()]]){
            mx[p].clear();
            res[p] = co[u];
            mx[p].emplace_back(u);
        } else if(cnt[co[u]] + 1 == cnt[co[mx[p].front()]]){
            res[p] += co[u];
            mx[p].emplace_back(u);
        }
    }
    cnt[co[u]]++;
}

void rem(int u){
    cnt[co[u]]--;
}

void dfs1(int u, int p){
    sz[u] = 1;
    for(int v : G[u]){
        if(v != p){
            dfs1(v, u);
            sz[u] += sz[v];
        }
    }
}

void dfs2(int u, int p, bool keep){
    int bmx = -1, bc = -1;
    for(int v : G[u]){
        if(v == p) continue;
        if(sz[v] > bmx){
            bmx = sz[v];
            bc = v;
        }
    }

    for(int v : G[u]){
        if(v != p and v != bc) dfs2(v, u, 0);
    }
    if(bc != -1){
        dfs2(bc, u, 1); //ele, mx
        swap(ch[u], ch[bc]);
        swap(mx[u], mx[bc]);
        swap(res[u], res[bc]);
    }

    if(DEBUG){
        cout << "CHK : " << u << "\n";
        for(int v : mx[u]) cout << v << " ";
        cout << "\n";
    }
    
    add(u, u);
    for(int v : G[u]){
        if(v != p and v != bc){
            for(int vv : ch[v]){
                add(u, vv);
            }
        }
    }

    if(DEBUG){
        cout << "CURRENT : " << u << "\n";
        for(int v : ch[u]){ 
            cout << v << " ";
        }
        cout << "\nMX : ";
        for(int v : mx[u]){
            cout << v << " ";
        }
        cout << "\n\n";
    }

    ans[u] = res[u];

    if(keep == 0){
        for(int v : ch[u]){
            rem(v);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> co[i];
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1, 1);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}