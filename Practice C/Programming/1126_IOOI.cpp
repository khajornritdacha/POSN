#include <bits/stdc++.h>
using namespace std;


int main(void){
	int n,K,mod = 2553, ans = 0;	cin >> n >> K;
    vector<int> dp(n+1, 1), qs(n+1, 1);
	for(int len = 1; len <= n; len++){
		vector<int> ndp(n+1), nqs(n+1);
		for(int sum = 1; sum <= n; sum++){
			ndp[sum] = qs[sum-1];
			if(sum-K-1 >= 0)
				ndp[sum] -= qs[sum-K-1];
			ndp[sum] = (ndp[sum]+mod)%mod;
			nqs[sum] = (nqs[sum-1]+ndp[sum])%mod;
		}
		ans = (ans+1ll*ndp[n]*ndp[n]*ndp[n])%mod;
		dp = ndp; qs = nqs;
	}
	cout << ans << "\n";
}

