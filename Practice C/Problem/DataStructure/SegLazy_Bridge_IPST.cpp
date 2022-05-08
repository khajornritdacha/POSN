//Task : IPST mar10_bridge
//sort by end points
//at the current end point ask for minimum in range [st[i], ed[i]]
//update minimum in range [st[i], ed[i]] with val+2 (crossing 2 more bridges)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9+10;

using pi = pair<int, int>;

int L, n, m, seg[4*N], lazy[4*N];
vector<pi> ord = {{0, 0}};
vector<int> bridge = {0};

inline void push(int node, int l, int r){
	if(lazy[node] == INF) return;
	seg[node] = min(seg[node], lazy[node]);
	if(l != r){
		lazy[node<<1] =  min(lazy[node<<1], lazy[node]);
		lazy[node<<1|1] = min(lazy[node<<1|1], lazy[node]);
	}
	lazy[node] = INF;
}

void up(int a, int b, int val, int l = 1, int r = m, int node = 1){
	if(a > b or b < l or a > r) return;
	push(node, l, r);
	if(a <= l and r <= b){
		lazy[node] = min(lazy[node], val);
		push(node, l, r);
		return;
	}
	int mid = (l+r)>>1;
	up(a, b, val, l, mid, node<<1), up(a, b, val, mid+1, r, node<<1|1);
	seg[node] = min(seg[node<<1], seg[node<<1|1]);
}

int ask(int a, int b, int l = 1, int r = m, int node = 1){
	if(a > b or b < l or a > r) return INF;
	push(node, l, r);
	if(a <= l and r <= b) return seg[node];
	int mid = (l+r)>>1;
	return min(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L >> n >> m;
	for(int i = 1; i <= n; i++){
		int st, ed; cin >> st >> ed;
		ord.emplace_back(st, ed);
	}
	for(int i = 1; i <= m; i++){
		int pos; cin >> pos;
		bridge.emplace_back(pos);
	}
	for(int i = 0; i <= 4*m; i++) lazy[i] = seg[i] = INF;

	sort(bridge.begin(), bridge.end());
	sort(ord.begin(), ord.end(), [&](const pi &A, const pi &B){
		if(A.second != B.second) return A.second < B.second;
		return A.first < B.first;
	});

	int ans = INF;
	for(auto [st, ed] : ord){
		// cout << "CUR : " << st << " " << ed << "\n";
		int val = INF;
		if(st == 0) val = 1;
		
		int lb = lower_bound(bridge.begin(), bridge.end(), st)-bridge.begin();
		int ub = upper_bound(bridge.begin(), bridge.end(), ed)-bridge.begin()-1;
		if(lb == 0) lb++;

		val = min(val, ask(lb, ub));
		// cout << lb << " " << ub << " " << val << "\n";
		up(lb, ub, val+2);

		if(ed == L) ans = min(ans, val);
	}

	cout << ans << "\n";

	return 0;
}