#include <bits/stdc++.h>
using namespace std;

const int N = 20, INF = 1e9+7;
using ll = long long;
using pi = pair<int,int>;

int n,W,w[N];
pi dp[1<<N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> W;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    for(int i = 1; i < (1<<n); i++) dp[i] = pi(INF, INF);

    for(int bit = 0; bit < (1<<n); bit++){
        for(int i = 0; i < n; i++){
            if(bit&(1<<i)) continue;
            int go = bit|(1<<i), nr = dp[bit].first, nw = dp[bit].second + w[i];

            if(nw > W){ nr++, nw = w[i]; }

            if(nr < dp[go].first){
                dp[go] = pi(nr, nw);
            } else if (nr == dp[go].first and nw < dp[go].second){
                dp[go].second = nw;
            }
        }
    }

    cout << dp[(1<<n)-1].first+1 << "\n";
}