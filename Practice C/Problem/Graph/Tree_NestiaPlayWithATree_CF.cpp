#include<bits/stdc++.h>
#define DEBUG true
#define int long long
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;
int n,ans;
vector<pi> edge,rm;
vector<int> leaf;
vector<vector<pi>> vec;
vector<bool> vi,use,chk;
///https://codeforces.com/contest/1521/problem/D

void dfs(int u, int p){
    vi[u] = true;
    int ch = 0;
    for(auto [v, idx] : vec[u]){
        if(v == p) continue;
        if(vi[v] or use[idx]) continue;
        dfs(v, u);
        ch++;
    }
    if(ch == 0 or ch == 1 and p == -1)
        leaf.emplace_back(u);
}

void gen(int u, int p){
    int ch = vec[u].size()-(p!=-1);
    for(auto [v, idx] : vec[u]){
        if(v == p) continue;
        gen(v, u);
        if(chk[v]){
            ch--, ans++;
            use[idx] = true;
            rm.emplace_back(u ,v);
        }
    }
    if(ch >= 2){
        chk[u] = true;
        for(auto [v, idx] : vec[u]){
            if(v == p) continue;
            if(ch <= 2) break;
            if(!chk[v]){
                ch--, ans++;
                use[idx] = true;
                chk[v] = true;
                rm.emplace_back(u ,v);
            }
        }
    }
}

void test_case(){
    cin >> n;
    ans = 0;
    vector<pi> res,rea;
    vec.resize(n+1); vi.resize(n+1, false); use.resize(n+1, false); chk.resize(n+1, false);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v, i);
        vec[v].emplace_back(u, i);
        edge.emplace_back(u, v);
    }

    gen(1, -1);

    for(int i=1; i<=n; i++){
        if(!vi[i]){
            dfs(i, -1);
            if(leaf.size() == 1)
                res.emplace_back(leaf[0], leaf[0]);
            else
                res.emplace_back(leaf[0], leaf[1]);
            leaf.clear();
        }
    }

    for(int i=1; i<res.size(); i++){
        rea.emplace_back(res[i-1].second, res[i].first);
    }
    assert(rm.size() == rea.size());
    cout << ans << "\n";
    for(int i=0; i<rm.size(); i++){
        cout << rm[i].first << " " << rm[i].second << " " << rea[i].first << " " << rea[i].second << "\n";
    }
    vec.clear(); vi.clear(); edge.clear(); chk.clear(); use.clear(); rm.clear();
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        test_case();
    }
}
