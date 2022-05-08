#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1583/problem/D

int n, ans[110], mn, mx, gr[110], le[110];

int main(void){
	cin >> n;

	for(int i = 1; i <= n; i++){
		cout << "? ";
		for(int j = 1; j <= n; j++){ //find the next number that greater than i
			if(j == i) cout << 2;
			else cout << 1;
			cout << " ";
		}
		cout << endl;

		int res; cin >> res;
		if(res == 0){
			mx = i;
		} else if(res != i){
			gr[i] = res;
			le[res] = i;
		}

		cout << "? ";
		for(int j = 1; j <= n; j++){
			if(j == i) cout << 1;
			else cout << 2;
			cout << " ";
		}
		cout << endl;
		
		cin >> res;
		if(res == 0){
			mn = i;
		} else if(res != i){
			le[i] = res;
			gr[res] = i;
		}
	}

	for(int i = n, cur = mx; i >= 1; i--, cur = le[cur]){
		ans[cur] = i;
	}

	cout << "! ";
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}