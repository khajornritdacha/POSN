#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, MR = 25010, CASE = 500;

int n, R, Q, sz[N], cnt[MR], re[N], tin[N], tout[N], ti, st[N];
vector<int> G[N], ch[N], sml[MR];
vector<vector<int>> ans;
vector<pair<int, int>> lar[MR];

void dfs1(int u, int p){
    sz[u] = 1;
    tin[u] = ++ti;
    for(int v : G[u]){
        dfs1(v, u);
        sz[u] += sz[v];
    }
    tout[u] = ti;
}

void dfs2(int u, int p, bool keep){
    int bc = -1;
    for(int v : G[u]) if(bc == -1 or sz[v] > sz[bc]) bc = v;

    for(int v : G[u]) if(v != bc) dfs2(v, u, 0);
    if(bc != -1){
        dfs2(bc, u, 1);
        swap(ch[u], ch[bc]);
    }
    ch[u].emplace_back(u);
    cnt[re[u]]++;

    for(int v : G[u]){
        if(v == bc) continue;
        for(int vv : ch[v]){
            cnt[re[vv]]++;
            ch[u].emplace_back(vv);
        }
    }
    for(int i = 1; i <= R; i++) ans[re[u]][i] += cnt[i];

    if(keep == 0){
        for(int v : ch[u]) cnt[re[v]]--;
    }
}

void chk(stack<int> st, int k){
    // cout << "CHKST : ";
    while(!st.empty()){
        // cout << st.top() << " ";
        assert(k <= st.top());
        st.pop();
    }
    // cout << "\n";
}

int getans(int r1, int r2){
    if(R <= CASE) return ans[r1][r2];

    int res = 0, idx = 0;    
    for(int i = 0, j = -1; i < sml[r2].size(); i++){
        while(idx > 0 and sml[r2][i] > st[idx]) idx--; //pop
        while(j+1 < lar[r1].size() and lar[r1][j+1].second < sml[r2][i]) j++;

        while(j+1 < lar[r1].size() and sml[r2][i] > lar[r1][j+1].first){ //add
            if(lar[r1][j+1].second >= sml[r2][i]) st[++idx] = lar[r1][j+1].second;
            j++;
        }

        // chk(st, sml[r2][i]);

        res += idx;
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> R >> Q;
    cin >> re[1];
    for(int i = 2; i <= n; i++){
        int p; cin >> p >> re[i];
        G[p].emplace_back(i);
    }

    dfs1(1, -1);
    if(R <= CASE){
        ans.resize(R+10, vector<int>(R+10));
        dfs2(1, -1, 1);
    }
    else {
        for(int i = 1; i <= n; i++){
            sml[re[i]].emplace_back(tin[i]);
            lar[re[i]].emplace_back(tin[i], tout[i]);
        }
        for(int i = 1; i <= R; i++){
            sort(sml[i].begin(), sml[i].end());
            sort(lar[i].begin(), lar[i].end());
        }

    }

    while(Q--){
        int r1, r2; cin >> r1 >> r2;
        cout << getans(r1, r2) << endl;
    }

    return 0;
}