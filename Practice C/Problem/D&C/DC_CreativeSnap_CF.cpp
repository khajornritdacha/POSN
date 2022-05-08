#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
using ll = long long;

///https://codeforces.com/problemset/problem/1111/C

int a[N],n,K;
ll A,B;
map<int, int> qs;

ll cal(int l, int r){
	auto itr = qs.upper_bound(r);
	if(itr != qs.begin()) itr--;
	auto itl = qs.lower_bound(l);
	if(itl != qs.begin()) itl--;
	int num = (itr->second)-(itl->second);
	if(num <= 0) return A; ///There is no avengers in this range
	else return B*num*(r-l+1);
}

ll solve(int l, int r){
    if(l == r) return cal(l, r);

    auto itr = qs.upper_bound(r);
	if(itr != qs.begin()) itr--;
	auto itl = qs.lower_bound(l);
	if(itl != qs.begin()) itl--;
	int num = (itr->second)-(itl->second);
    //cout << l << " " << r << "\n";
    //cout << itl->first << " " << itr->first << "\n";
	if(num <= 0)
        return A; ///There is no avengers in this range then we can return unless it will take O(2^n) because it will divide into l == r in which there are 2^n of them!

	int mid = (l+r)>>1;
	ll tmp = min(cal(l, r), solve(l, mid)+solve(mid+1, r));
	return tmp;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> K >> A >> B;
	for(int i = 1; i <= K; i++){
		cin >> a[i];
		qs[a[i]]++;
	}
	qs[0] = 0;
	for(auto it = qs.begin();  it != qs.end(); it++){
		if(it == qs.begin()) continue;
		auto it2 = it;
		it2--;
		it->second += it2->second;
	}

	if(DEBUG){
		cout << "MP\n";
		for(auto [val, cnt] : qs){
			cout << val << " " << cnt << "\n";
		}
		cout << "-----------------\n";
	}

	cout << solve(1, 1<<n) << "\n";
	return 0;
}
