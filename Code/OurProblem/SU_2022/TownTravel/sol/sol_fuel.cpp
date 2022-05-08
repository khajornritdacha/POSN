#include <bits/stdc++.h>
using namespace std;
vector<array<int, 3>> v;
vector<array<int, 4>> q;
bitset<200001> ans;
int pa[100000];

int findpa(int a){
	return pa[a] == a ? a : pa[a] = findpa(pa[a]);
}

int main(){
	int N, M, Q;
	scanf("%d %d %d", &N, &M, &Q);
	for(int i = 0; i < N; i++) pa[i] = i;
	for(int i = 0, ui, vi, wi; i < M; i++){
		scanf("%d %d %d", &ui, &vi, &wi);
		v.push_back({wi, ui, vi});
	}
	sort(v.begin(), v.end());
	for(int i = 0, a, b, k; i < Q; i++){
		scanf("%d %d %d", &a, &b, &k);
		q.push_back({k, a, b, i});
	}
	sort(q.begin(), q.end());
	int ptr = 0;
	for(int i = 0; i < M; i++){
		int ux = v[i][1], vx = v[i][2];
		if(findpa(ux) != findpa(vx)){
			pa[findpa(ux)] = findpa(vx);
		}
		while(ptr < Q && q[ptr][0] <= v[i][0]){
			if(findpa(q[ptr][1]) == findpa(q[ptr][2])) ans[q[ptr][3]] = 1;
			ptr++;
		}
	}
	for(int i = 0; i < Q; i++){
		printf(ans[i] ? "Yes\n" : "No\n");
	}
}