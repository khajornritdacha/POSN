//precalculate another maximum rectangle sum in array "pre"
//pre := the largest rectangle sum that its start row is greater than current end-row atleast 2 (current r +2 <= pre.r)
//since "pre" has to propagate into r-1, or c1-1, or c2+1 (start sooner or larger size or both)

//then the problem has been decomposition into finding maximum subarray sum in 2D for each point and add it with precalculated another rectangle

//this is written in column-based and larger rectangle always on the top of the smaller one

#include <bits/stdc++.h>
using namespace std;

const int N = 310, INF = 1e9+10;

int R, C, pre[N][N][N], arr[N][N], qs[N][N];

int solve(){
	int res = -INF;

	for(int r = 0; r <= R; r++) for(int c1 = 0; c1 <= C; c1++) for(int c2 = 0; c2 <= C; c2++) pre[r][c1][c2] = -INF;
	
	for(int r = 1; r <= R; r++){
		for(int c = 1; c <= C; c++){
			qs[r][c] = qs[r][c-1] + arr[r][c];
		}
	}

	for(int c1 = 1; c1 <= C; c1++){
		for(int c2 = c1; c2 <= C; c2++){
			int sum = 0;
			for(int r = R; r >= 3; r--){
				int cur = qs[r][c2]-qs[r][c1-1];
				if(sum + cur > cur) sum += cur;
				else sum = cur;
				pre[r-2][c1][c2] = sum;
			}
		}
	}

	for(int r = R; r >= 1; r--){
		for(int sz = 1; sz <= C; sz++){
			for(int c1 = 1; c1 <= C-sz+1; c1++){
				int c2 = c1+sz-1;
				
				for(int kr : {0, -1}){
					for(int kc1 : {0, -1}){
						for(int kc2 : {0, 1}){
							pre[r+kr][c1+kc1][c2+kc2] = max(pre[r+kr][c1+kc1][c2+kc2], pre[r][c1][c2]);
						}
					}
				}
			}
		}
	}

	for(int c1 = 1; c1 <= C; c1++){
		for(int c2 = c1; c2 <= C; c2++){
			int sum = 0;
			for(int r = 1; r <= R; r++){
				int cur = qs[r][c2]-qs[r][c1-1];
				if(sum + cur > cur) sum += cur;
				else sum = cur;

				res = max(res, sum + pre[r][c1][c2]);
			}
		}
	}
	return res;
}

void revR(){
	for(int c = 1; c <= C; c++){
		for(int r = 1; r <= R/2; r++){
			swap(arr[r][c], arr[R-r+1][c]);
		}
	}
}

void _rotate(){
	int bb[C+5][R+5] = {};
	for(int r = 1; r <= R; r++){
		for(int c = 1; c <= C; c++){
			bb[c][R-r+1] = arr[r][c];
		}
	}

	swap(R, C);
	for(int r = 1; r <= R; r++){
		for(int c = 1; c <= C; c++){
			arr[r][c] = bb[r][c];
		}
	}
}

inline void pri(){
	for(int r = 1; r <= R; r++){
		for(int c = 1; c <= C; c++){
			cout << arr[r][c] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cin >> arr[i][j];
		}
	}

	int ans = solve();

	revR();
	// cout << "\nREVERSE Row\n";
	// pri();

	ans = max(ans, solve());

	revR();
	_rotate();
	// cout << "\nROTATE\n";
	// pri();

	ans = max(ans, solve());
	
	revR();
	// cout << "\nREVERSE Row\n";
	// pri();

	ans = max(ans, solve());


	cout << ans << "\n";

	return 0;
}