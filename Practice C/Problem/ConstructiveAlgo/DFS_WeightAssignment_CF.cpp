#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

//print -1 iff it exists before its ancestor
//https://codeforces.com/problemset/problem/1611/D

int root, n, idx[N], B[N], P[N];
long long ans[N], dis[N];
bool ok;
set<int> ss;
vector<int> G[N];

void dfs(int u){
    if(ss.lower_bound(idx[u]) != ss.end()){
        ok = false;
    }
    ss.insert(idx[u]);
    for(int v : G[u]){
        dfs(v);
    }
    ss.erase(idx[u]);
}

void test_case(){
    ok = true;
    cin >> n;
    for(int i = 1; i <= n; i++) G[i].clear(), dis[i] = ans[i] = 0;

    for(int i = 1; i <= n; i++){
        cin >> B[i];
        if(B[i] == i) root = i;
        else G[B[i]].emplace_back(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> P[i];
        idx[P[i]] = i;
    }

    dfs(root);

    if(!ok){
        cout << "-1\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        if(P[i] == root) continue;
        ans[P[i]] = dis[P[i-1]] + 1 - dis[B[P[i]]];
        dis[P[i]] = dis[B[P[i]]] + ans[P[i]];
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";


    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}