#include "askask.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

std::vector<int> find_bombs(int N){
	int pw = 2, sz = N, cursz = N/2;
    vector<vector<int>> ask;

    for(; sz > 1; sz /= 2){
        vector<int> vec;
        int pos = 1, step = N/pw*2;

        for(; pos < N; ){
            int ed = pos+cursz-1;
            for(int i = pos; i <= ed; i++){
                vec.emplace_back(i-1);
                // cout << i << " ";
            }

            pos += step;
        }

        // cout << "\n";

        ask.emplace_back(vec);

        pw *= 2;
        cursz /= 2;
    }

	// for(int i = 0; i < ask.size(); i++){
	// 	for(int v : ask[i]){
	// 		cout << v << " ";
	// 	}
	// 	cout << "\n";
	// }

	vector<bool> res = analyse(ask);

	int l = 1, r = N;
	for(int i = 0; i < res.size(); i++){
		int mid = (l+r)>>1;
		if(res[i]){
			r = mid;
		} else {
			l = mid+1;
		}
	}

	return {l-1, l-1};
}