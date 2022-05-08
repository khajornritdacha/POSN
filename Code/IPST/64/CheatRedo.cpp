#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
	#include "cheat.h"
#endif	

const int N = 2e5+10;

int ti, sz[N], pa[N], wa[N], dep[N];
bool init;

int fi(int x){
	if(pa[x] == x){
		return x;
	}
	int res = fi(pa[x]);
	dep[x] = dep[pa[x]]+1;
	return res;
}

inline void ini(){
	init = true;
	for(int i = 1; i < N; i++) pa[i] = i, sz[i] = dep[i] = 1;
}

void cheat(int person1, int person2){
	if(!init) ini();
	int u = person1, v = person2;
	ti++;
	u = fi(u), v = fi(v);
	if(u == v) return;
	if(sz[u] < sz[v]) swap(u, v);
	
	sz[u] += sz[v];
	pa[v] = u;
	wa[v] = ti;
	dep[v] = dep[u]+1;
}

int investigate(int person1, int person2){
	if(!init) ini();
	int u = person1, v = person2;
	int pu = fi(u), pv = fi(v);

	if(pu != pv) return -1;

	int res = 0;
	if(dep[u] < dep[v]) swap(u, v);
	while(dep[u] > dep[v]){
		res = max(res, wa[u]);
		u = pa[u];
	}
	while(u != v){
		res = max({res, wa[u], wa[v]});
		u = pa[u], v = pa[v];
	}
	return res;
}

#ifdef LOCAL

int main(void){
	int n, Q; cin >> n >> Q;
	while(Q--){
		int op; cin >> op;
		if(op == 0){ //cheat
			int u, v; cin >> u >> v;
			cheat(u, v);
		} else if(op == 1){ //investigate
			int u, v; cin >> u >> v;
			cout << investigate(u, v) << "\n";
		}
	}
	return 0;
}

#endif