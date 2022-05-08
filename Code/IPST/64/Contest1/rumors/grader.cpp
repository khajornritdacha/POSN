#include "rumors.h"
#include <cstdio>
#include <cassert>
#include <vector>

int main(){
	int N, K, Q;
	std::vector<int> d;
	scanf("%d%d%d",&N,&K,&Q);
	assert(1 <= N && N <= 2000);
	assert(1 <= K && K <= 100000);
	assert(1 <= Q && Q <= 800000);
	for(int i = 0; i < N; i++){
		int x;
		scanf("%d", &x);
		d.push_back(x);
		assert(x <= 9999999);
		if(i > 0) assert(d[i-1] < d[i]);
	}
	std::vector<int> qx, qj;
	for(int i = 0; i < Q; i++){
		int x, j;
		scanf("%d%d",&x,&j);
		assert(0 <= x && x < N);
		assert(0 <= j && j <= 9999999);
		qx.push_back(x);
		qj.push_back(j);
	}
	std::vector<int> answers = analyze_rumors(N, K, Q, d, qx, qj);
	for(int ans : answers){
		printf("%d\n", ans);
	}
	return 0;
}
