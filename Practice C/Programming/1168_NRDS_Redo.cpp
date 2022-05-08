#include <bits/stdc++.h>
using namespace std;

vector<int> seq;

void gen(int cur = 0, int pre = 0){
	seq.push_back(cur);
	for(int i = pre+1; i <= 9; i++){
		gen(cur*10+i, i);
	}
	return;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	gen();

	sort(seq.begin(), seq.end());

	/*for(int ss : seq)
		cout << ss << " ";
	cout << "\n";*/

	int Q; cin >> Q;
	while(Q--){
		long long n; cin >> n;
		if(n >= (long long)seq.size()) cout << "-1\n";
		else cout << seq[n] << "\n";
	}
	return 0;
}
