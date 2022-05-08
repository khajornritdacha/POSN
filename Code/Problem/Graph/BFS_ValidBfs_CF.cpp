#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n,in[N];
queue<int> qq;
set<int> G[N];
bool cou[N];

///https://codeforces.com/problemset/problem/1037/D

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    for(int i = 1; i <= n; i++){
        cin >> in[i];
    }

    int idx = 2;
    bool ok = true;
    qq.emplace(1);
    while(!qq.empty()){
        int u = qq.front(); qq.pop();

        while(!G[u].empty()){
            auto it = G[u].find(in[idx]);
            if(it == G[u].end()){
                ok = false;
                break;
            }

            qq.emplace(in[idx]);
            G[u].erase(in[idx]);
            G[in[idx]].erase(u);
            idx++;
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}

/*
6
1 2
1 5
2 3
2 4
5 6
1 5 2 3 4 6
*/