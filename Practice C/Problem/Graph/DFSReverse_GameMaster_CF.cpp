//https://codeforces.com/problemset/problem/1608/C
//count the number of elements reached by root with dfs on reversed graph

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

bool reach[N];
vector<int> G[N];

void dfs(int u){
    reach[u] = true;
    for(int v : G[u]){
        if(!reach[v]) dfs(v);
    }
}

void TC(){
	int n, st; cin >> n;
    for(int i = 0; i <= n; i++) reach[i] = 0, G[i].clear();

    for(int t = 0; t < 2; t++){
        vector<pair<int, int>> vec;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            vec.emplace_back(x, i);
        }

        sort(vec.rbegin(), vec.rend());
        if(t == 0) st = vec[0].second;
        for(int i = 0; i+1 < vec.size(); i++){
            int u = vec[i].second, v = vec[i+1].second;
            G[v].emplace_back(u);
        }
    }

    dfs(st);

    for(int i = 1; i <= n; i++) cout << reach[i];
    cout << "\n";

	return;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) TC();

	return 0;
}