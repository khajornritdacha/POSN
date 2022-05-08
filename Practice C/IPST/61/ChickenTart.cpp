#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9+10;

int arr[N], n, M, K, pre[N], suf[N], sz, mxp[N], mxs[N];

bool chk(int mid){
	for(int i = 1, cur = 0, cnt = 1, num = 0; i <= n; i++){
		num++;
		if(cur + arr[i] > mid or num > M){
			cnt++;
			cur = 0;
			num = 1;
		}

		cur += arr[i];
		pre[i] = cnt;
	}


	for(int i = n, cur = 0, cnt = 1, num = 0; i >= 1; i--){
		num++;
		if(cur + arr[i] > mid or num > M){
			cnt++;
			cur = 0;
			num = 1;
		}

		cur += arr[i];
		suf[i] = cnt;
	}

	for(int l = 1, r = sz; r <= n; l++, r++){
		if(pre[l-1] + 1 + suf[r+1] <= K and l-1+n-r >= K-1 and mxp[l-1] <= mid and mxs[r+1] <= mid){
			return true;
		}
	}

	return false;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> M >> K;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		mxp[i] = max(arr[i], mxp[i-1]);
	}
	for(int i = n; i >= 1; i--) mxs[i] = max(arr[i], mxs[i+1]);
	sz = min(n-K+1, M);

	int l = 0, r = INF, ans = -1;
	while(l <= r){
		int mid = (l+r)>>1;
		if(chk(mid)){
			ans = mid;
			r = mid-1;
		} else {
			l = mid+1;
		}		
	}

	cout << ans << "\n";

	return 0;
}