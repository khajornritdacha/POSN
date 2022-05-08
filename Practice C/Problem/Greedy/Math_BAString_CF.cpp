//https://codeforces.com/problemset/problem/1620/C
//there is a chance that the number of different AB string is greater than 9e18
//function mul is created to handle it
#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e18;

long long mul(long long a, long long b){
	if(a > INF/b) return 0;
	return a * b;
}

void TC(){
	int n, K;
	long long want;
	cin >> n >> K >> want;

	char arr[n+10] = {};
	for(int i = 1; i <= n; i++) cin >> arr[i];

	long long pw = 1, cur = 1;
	vector<pair<long long, long long>> vec;
	for(int i = n, cnt = 0; i >= 1; i--){
		if(arr[i] == '*' ){
			cnt++;
			if(i == 1 or arr[i-1] != '*'){
				vec.emplace_back(1ll*cnt*K, pw);
				pw = mul(pw, cnt*K+1); //if pw exceed 2e18 then it is exceed the range
				cnt = 0;
			}
		}
	}


	reverse(vec.begin(), vec.end());
	// cout << "PRECAL\n";
	// for(auto [x, y] : vec) cout << x << " " << y << "\n";
	// cout << "\n";

	int idx = 1;
	string ans = "";

	for(auto &[lim, cp] : vec){

		while(idx <= n and arr[idx] != '*'){
			ans.push_back('a');
			idx++;
		}

		if(cp != 0){ //add b iff it is valid(not overflow)
			for(int k = lim; k >= 0; k--){

				if(mul(k, cp) and cur+k*cp <= want){ //mul cannot return 0 if it overflows
					cur += k*cp;

					for(int j = 0; j < k; j++) ans.push_back('b');
					
					break;
				}
			}
		}

		while(idx <= n and arr[idx] == '*'){
			idx++;
		}
	}

	while(idx <= n and arr[idx] != '*'){
		ans.push_back('a');
		idx++;
	}

	cout << ans << "\n";

	return;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) TC();

	return 0;
}