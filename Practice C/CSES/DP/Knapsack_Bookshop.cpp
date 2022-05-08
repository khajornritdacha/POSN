#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n,X,H[N],S[N],dp[N*100];

int main(void){
	cin >> n >> X;
	for(int i = 1; i <= n; i++) cin >> H[i];
	for(int i = 1; i <= n; i++) cin >> S[i];
	
	for(int i = 1; i <= n; i++){
		for(int w = X; w >= H[i]; w--){
			dp[w] = max(dp[w], dp[w-H[i]]+S[i]);
		}
	}
	
	int ans = 0;
	for(int w = 0; w <= X; w++) ans = max(ans, dp[w]);
	cout << ans << "\n";
}
