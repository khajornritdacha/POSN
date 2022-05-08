#include <bits/stdc++.h>
using namespace std;

using lb = long double;

lb a[5][5],ans=1e18;
int R,C,pr[] = {-1,-1,-1,0,0,1,1,1}, pc[] = {-1,0,1,-1,1,-1,0,1};
bool vi[5][5];

void solve(int lv = 0, lb now = 0){
	if(lv == R*C){
		ans = min(ans, now);
		return;
	}
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			lb tmp = 0, tmp2 = a[i][j];
			if(!vi[i][j]){
				vi[i][j] = true;
				tmp = a[i][j]*0.1;
				now += tmp2;
				for(int k = 0; k < 8; k++){
					a[i+pr[k]][j+pc[k]] += tmp;
				}
				solve(lv+1, now);
				now -= tmp2;
				for(int k = 0; k < 8; k++){
					a[i+pr[k]][j+pc[k]] -= tmp;
				}
				vi[i][j] = false;
			}
		}
	}
	return;
}

int main(void){
	cin >> R >> C;
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cin >> a[i][j];
		}
	}

	solve();
	
	cout << setprecision(2) << fixed << ans << "\n";
	return 0;
}
