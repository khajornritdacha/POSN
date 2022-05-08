#include "lingling.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5+10;

int n, rp[MXN], go[MXN];

void init_monkeys(std::vector<int> P, int Q){
	n = P.size();
	for(int i = n; i >= 1; i--){
		rp[i] = P[i-1]+1;
		go[i] = rp[i];
	}

}

long long minimum_branches(int L, int R){
	set<int> ss;
	L++, R++;
	for(int i = L; i <= R; i++){
		if(rp[i] < L or rp[i] > R) return -1;
		if(ss.count(rp[i])) return -1;
		ss.insert(rp[i]);
	}

	vector<bool> vi(n+5, false);

	long long ans = 0;
	for(int i = L; i <= R; i++){
		if(vi[i]) continue;
		vi[i] = true;
		int u = rp[i];
		vector<int> cur;
		cur.emplace_back(i);
		while(u != i){
			vi[u] = true;
			cur.emplace_back(u);
			u = rp[u];
		}

		sort(cur.begin(), cur.end(), [&](const int &a, const int &b){
			return rp[a] < rp[b];
		});

		int sz = cur.size(), pat = 0;
		vector<int> tmp;
		for(int l = 0, r = sz-1; l <= r; pat = 1-pat){
			int res = 0;
			int idx = (pat == 0 ? l : r);
			if(rp[idx] < idx){
				for(int v : tmp) if(v < idx) res++;
			} else {
				for(int v : tmp) if(v > idx) res++;
			}
			ans += abs(rp[idx]-idx)-res;
			
			tmp.emplace_back(rp[idx]);

			if(pat == 0) l++;
			else r--;
		}
	}
	
	return ans;
}