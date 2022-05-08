#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

int a[N],tmp[N],n;

///https://www.spoj.com/problems/INVCNT/

ll solve(int l, int r){
	if(l == r) return 0;
	int mid = (l+r)>>1;
	ll res = solve(l, mid)+solve(mid+1, r);
	int i = l, j = mid+1, k = l; ///i -> left pointer, j -> right pointer, k -> new array pointer
	while(i <= mid and j <= r){
		if(a[j] < a[i]){
			res += (mid-i+1); ///Count inversion if and only if the least element in left side is less than the least element of right side
			tmp[k++] = a[j++];
		}else{
			tmp[k++] = a[i++];
		}
	}
	while(i <= mid) tmp[k++] = a[i++];
	while(j <= r) tmp[k++] = a[j++];
	for(int t = l; t <= r; t++) a[t] = tmp[t];
	return res;
}

void test_case(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << solve(1, n) << "\n";
	return;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		test_case();
	}
	return 0;
}
