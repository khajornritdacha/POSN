#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10, mod = 30011;

//dp(k, i) = sum(dp(k-1, j)); st[i][b] <= j <= ed[i][b]
//Just compute the entire range and subtract banned dp out

int n[2], K, L, dp[12][N], sz[N][2], st[N][2], qs[12][N];
vector<int> ban[N][2], pb[N][2];

inline void add(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

inline void sub(int &a, int b){
	a -= b;
	if(a < 0) a += mod;
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n[0] >> n[1] >> K >> L;
	for(int i = 1; i <= L; i++){
		int x, y; cin >> x >> y;
		pb[x][0].emplace_back(y);
		pb[y][1].emplace_back(x);
	}

	for(int b : {0, 1}){
		for(int i = 1; i <= n[b]; i++){
			cin >> sz[i][b] >> st[i][b];
			
			//precal dp
			dp[0][i] = 1;
			qs[0][i] = qs[0][i-1];
			add(qs[0][i], dp[0][i]);
			
			//ban
			sort(pb[i][b].begin(), pb[i][b].end()); //we must sort first. For example, if l[1] = 1, r[1] = 3 and ban (1, 4), ban(1, 2)
			int l = st[i][b], r = st[i][b] + sz[i][b] - 1; //then l[1] = 1, r[1] = 5 and subtract 2, 4 out afterward
			for(int c : pb[i][b]){
				if(l <= c and c <= r){
					r++;
					sz[i][b]++;
					ban[i][b].emplace_back(c);
				}
			}
		}
	}

	int ans = 0;
	for(int k = 1, b = 0; k <= K; k++, b = 1-b){		
		for(int i = 1; i <= n[b]; i++){
			int r = st[i][b] + sz[i][b]-1, l = st[i][b];
			add(dp[k][i], (qs[k-1][r]-qs[k-1][l-1]+mod)%mod);

			for(int l : ban[i][b]){
				sub(dp[k][i], dp[k-1][l]);
			}

			if(b == 0)
				add(ans, dp[k][i]);
			qs[k][i] = qs[k][i-1];
			add(qs[k][i], dp[k][i]);
		}		
	}

	cout << ans << "\n";

	return 0;
}