#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 3e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,m,sz,cnt;
vector<pi> G[N][2];
bool vi[N][2],ok;

///https://codeforces.com/problemset/problem/1594/D

void dfs(int u, int cd, int p, int pcd){
    //cout << u << " " << cd << " " << p << " " << pcd << " " << vi[u][cd] << "\n";
    if(vi[u][cd]) return;
    if(vi[u][!cd]){ ok = false; return; }
    vi[u][cd] = true;
    sz++;
    cnt += cd;
    for(auto [v, go] : G[u][cd]){
        if(v == p and go == pcd) continue;
        dfs(v, go, u, cd);
    }
}

void test_case(){
    cin >> n >> m;
    ok = true;
    for(int i = 1; i <= m; i++){
        int u,v;
        string str;
        cin >> u >> v >> str;
        if(str[0] == 'i'){ ///imposter
            G[u][0].emplace_back(v, 1);
            G[u][1].emplace_back(v, 0);
            G[v][1].emplace_back(u, 0);
            G[v][0].emplace_back(u, 1);
        }else{ ///crewmate
            G[u][0].emplace_back(v, 0);
            G[u][1].emplace_back(v, 1);
            G[v][0].emplace_back(u, 0);
            G[v][1].emplace_back(u, 1);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vi[i][0] and !vi[i][1]){
            cnt = 0, sz = 0;
            dfs(i, 0, -1, -1);
            ans += max(cnt, sz-cnt);
        }
    }

    if(!ok) ans = -1;
    cout << ans << "\n";

    for(int i = 0; i <= n; i++){
        G[i][0].clear(); G[i][1].clear();
        vi[i][0] = vi[i][1] = false;
    }
}


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
