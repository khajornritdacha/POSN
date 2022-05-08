#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 1e8;
int n;
vector<int> way[maxn], yaw[maxn];
int vis[maxn], dp[maxn][2];
int one, a, b;
void cycle(int u, int parent) {
	vis[u] = 1;
	for(auto v : way[u]) {
		if(!vis[v]) cycle(v, u);
		else {
			a = u;
			b = v;
		}
	}
}
void reset_vis(int u, int parent) {
	vis[u] = 0;
	for(auto v : yaw[u]) {
		if(vis[v]) reset_vis(v, u);
	}
}
void dfs(int u, int parent) {
	vis[u] = 1;

	dp[u][0] = 1;
	dp[u][1] = 0;
	for(auto v : yaw[u]) {
		if(vis[v]) continue;
		dfs(v, u);
		dp[u][0] += min(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0];
	}
	if(u == b && one == true) dp[u][1] = inf;
	// printf("\tdp %d = %d and %d\n",u,dp[u][0],dp[u][1]);
}
void solve(int tnum) {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		way[i].clear();
		yaw[i].clear();
	}
	for(int i=1;i<=n;i++) {
		int x; scanf("%d",&x);
		way[i].push_back(x);
		yaw[x].push_back(i);
	}
	// find cycle for each component
	int ans = 0;
	for(int i=1;i<=n;i++) vis[i] = 0;
	for(int u=1;u<=n;u++) {
		if(vis[u]) continue;

		// find a -> b
		cycle(u, 0);
		int res = inf;
		// 1. solve case a = 0
		reset_vis(a, 0);
		one = false;
		dfs(a, 0);
		res = min(res, dp[a][0]);
		// 2. solve case a = 1
		reset_vis(a, 0);
		one = true;
		dfs(a, 0);
		res = min(res, dp[a][1]);
		ans += res;
		// printf("cycle %d: %d\n",a,res);
	}
	printf("%d\n", ans);
}
int main() {
	int tnum; scanf("%d", &tnum);
	for(int i=1;i<=tnum;i++) solve(i);
}
