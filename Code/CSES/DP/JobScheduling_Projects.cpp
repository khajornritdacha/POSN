#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;
using tu = tuple<int,int,int>;

int n;
ll dp[N];
vector<tu> job;

int main(void){
	cin >> n;
	job.emplace_back(0, 0, 0);
	for(int i = 1; i <= n; i++){
		int s,t,w;
		cin >> s >> t >> w;
		job.emplace_back(t, s, w);
	}

	sort(job.begin(), job.end());
	
	vector<int> ed = {0};
	for(int i = 1; i <= n; i++){
		auto [t, s, w] = job[i];
		int k = lower_bound(ed.begin(), ed.end(), s)-ed.begin()-1;
		dp[i] = max(dp[i-1], dp[k]+w);
		ed.emplace_back(t);
	}
	cout << dp[n] << "\n";
}
