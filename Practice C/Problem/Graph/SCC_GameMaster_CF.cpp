//https://codeforces.com/problemset/problem/1608/C
//count the elements that has can reach the root node
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int ti, low[N], id[N], n;
bool inst[N];
stack<int> st;
vector<int> G[N];

void SCC(int u){
	low[u] = id[u] = ++ti;
	st.push(u);
	inst[u] = true;
	for(int v : G[u]){
		if(!id[v]) SCC(v);
		if(inst[v]) low[u] = min(low[u], low[v]);
	}

	if(low[u] == id[u]){
		while(true){
			int now = st.top(); st.pop();
			low[now] = low[u];
			if(now == u) break;
		}
	}
}

void TC(){
	ti = 0;
	cin >> n;
	assert(st.empty());
	for(int i = 0; i <= n; i++){
		low[i] = id[i] = inst[i] = 0;
		G[i].clear();
	}

	int st = 0;
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
			G[u].emplace_back(v);
			// cout << "Edge : " << u << " -> " << v << "\n";
		}
	}

	SCC(st);

	for(int i = 1; i <= n; i++) cout << (low[i] == 1);
	cout << "\n";


	return;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) TC();

	return 0;
}