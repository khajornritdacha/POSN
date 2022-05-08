#include <bits/stdc++.h>
#include "askask.h"
#include <vector>
using namespace std;

void cal(int &l1, int &r1, int &l2, int &r2, bool resf, bool resb, int resz = -1){
	int mid1 = (l1+r1)/2;
	int mid2 = (l2+r2)/2;
	assert(resf|resb);

	if(resz == -1){
		if(resf == 1 and resb == 0){
			r1 = mid1;
			r2 = mid2;
		} else if(resf == 0 and resb == 1){
			l1 = mid1+1;
			l2 = mid2+1;
		} else {
			r1 = mid1;
			l2 = mid2+1;
		}
	} else {
		if(resf == 1 and resb == 0){
			r1 = mid1;
			r2 = mid2;
		} else if(resf == 0 and resb == 1){
			l1 = mid1+1;
			l2 = mid2+1;
		} else if(resz == 1){
			r1 = mid1;
			l2 = mid2+1;
		} else {
			l1 = mid1+1;
			r2 = mid2;
		}
	}
	return;
}

std::vector<int> find_bombs(int N){
	int l1 = 1, r1 = N, l2 = 1, r2 = N;
	int sz = N/4, step = N/2, addi = 1;

	vector<vector<int>> ask;
	{
		vector<int> vec;
		for(int i = 0; i < N/2; i++){
			vec.emplace_back(i);
		}
		ask.emplace_back(vec);
		vec.clear();

		for(int i = N/2; i < N; i++){
			vec.emplace_back(i);
		}
		ask.emplace_back(vec);
	}
	
	for(; sz >= 1; sz /= 2){
		int pos = 1;
		
		vector<int> vec;
		for(; pos <= N; ){
			int ed = pos+sz-1;
			for(int i = pos; i <= ed; i++){
				vec.emplace_back(i-1);
			}
			pos += step;
		}
		ask.emplace_back(vec);
		vec.clear();

		pos = sz+1;
		for(; pos <= N; ){
			int ed = pos+sz-1;
			for(int i = pos; i <= ed; i++){
				vec.emplace_back(i-1);
			}
			pos += step;
		}
		ask.emplace_back(vec);
		vec.clear();

		pos = 1; 
		for(int k = 0; k < addi; k++){
			int ed = pos+sz-1;
			for(int i = pos; i <= ed; i++){
				vec.emplace_back(i-1);
			}
			pos += step;
		}
		ask.emplace_back(vec);
		vec.clear();

		step /= 2;
		addi *= 2;
	}

	for(int i = 0; i < ask.size(); i++){
		for(int v : ask[i]){
			cout << v << " ";
		}
		cout << "\n";
	}

	vector<bool> res = analyse(ask);

	cal(l1, r1, l2, r2, res[0], res[1]);
	cout << "Range : " << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
	for(int i = 2; i < res.size(); i += 3){
		cal(l1, r1, l2, r2, res[i], res[i+1], res[i+2]);
		cout << "Result : " << res[i] << " " << res[i+1] << " " << res[i+2] << "\n";
		cout << "Range : " << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
	}

	return {l1-1, l2-1};
}