//CR: Hydrolyzed~

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9+10;

struct DATA{
	int val, idx;
	DATA(int a = 0, int b = 0) : val(a), idx(b) {}
	bool operator < (const DATA &o) const{
		return val > o.val;
	}
};

int n, K, arr[N], val[2*N], L[2*N], R[2*N];
bitset<2*N> del;
priority_queue<DATA> pq;

void chk(priority_queue<DATA> pq){
	cout << "----------------------\nCHK\n";
	while(!pq.empty()){
		cout << pq.top().val << " " << pq.top().idx << "\n";
		pq.pop();
	}
	cout << "\n\n";
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> K;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		val[i-1] = arr[i] - arr[i-1];
	}

	for(int i = 1; i < n; i++){
		pq.emplace(val[i], i);
		L[i] = i-1;
		R[i] = i+1;
	}
	val[0] = val[n] = INF;
	R[n] = n;
	int ans = 0, sz = n;

	// chk(pq);

	while(K--){
		DATA cur;
		// chk(pq);
		while(!pq.empty()){
			cur = pq.top(); pq.pop();
			// cout << "DEL : " << cur.idx << "\n";
			if(!del[cur.idx]) break;
		}

		// cout << cur.idx << "\n";
		ans += cur.val;
		int idx = cur.idx;
		del[L[idx]] = del[R[idx]] = true;

		val[++sz] = val[L[idx]] + val[R[idx]] - val[idx];
		L[sz] = L[L[idx]];
		R[sz] = R[R[idx]];
		R[L[sz]] = sz;
		L[R[sz]] = sz;
		pq.emplace(val[sz], sz);
	}

	cout << ans << "\n";

	return 0;
}