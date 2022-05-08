#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

//http://www.usaco.org/index.php?page=viewproblem2&cpid=696

int fen[N], ans[N], sz[N], co[N], n;
vector<int> ch[N], G[N];
unordered_map<int, int> idx;

void up(int i, int val){
    assert(i > 0);
    while(i < N){
        fen[i] += val;
        i += i&-i;
    }
}

int sum(int i){
    int res = 0;
    while(i){
        res += fen[i];
        i -= i&-i;
    }
    return res;
}

void add(int p, int u){
    ch[p].emplace_back(u);
    up(idx[co[u]], 1);
}

void rem(int u){
    up(idx[co[u]], -1);
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
    int mx = -1, bc = -1;
    for(int v : G[u]){
        if(v != p and sz[v] > mx){
            mx = sz[v], bc = v;
        }
    }

    for(int v : G[u]){
        if(v != p and v != bc) dfs2(v, u, 0);
    }
    if(bc != -1){
        dfs2(bc, u, 1);
        swap(ch[u], ch[bc]);
    }
    
    add(u, u);
    for(int v : G[u]){
        if(v != p and v != bc){
            for(int vv : ch[v]){
                add(u, vv);
            }
        }
    }

    ans[u] = sum(n)-sum(idx[co[u]]);

    if(keep == 0){
        for(int v : ch[u]) rem(v);
    }
}

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(!name.empty()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void){
    setIO("promote");
    cin >> n;
    vector<int> lis;
    for(int i = 1; i <= n; i++){
        cin >> co[i];
        lis.emplace_back(co[i]);
    }
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        G[p].emplace_back(i);
    }

    sort(lis.begin(), lis.end());
    lis.resize(unique(lis.begin(), lis.end())-lis.begin());
    for(int i = 0; i < lis.size(); i++) idx[lis[i]] = i+1;

    dfs1(1, -1);
    dfs2(1, -1, 1);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}