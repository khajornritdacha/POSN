#include <bits/stdc++.h>
using namespace std;

const int N = 310;
using ll = long long;

int R,C,K;
ll qs[N][N];

///qs(c,d)-qs(a,d)-qs(c,b)+qs(a,b) <= K
///qs(c,d)-qs(c,b)-K <= qs(a,d)-qs(a,b)

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> K;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> qs[i][j];
            qs[i][j] += qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    long long ans = 0;
    for(int b = 0; b <= C; b++){
        for(int d = b+1; d <= C; d++){
            vector<ll> cur = {0}; ///qs[0][d]-qs[0][b]
            for(int c = 1; c <= R; c++){
                ans += c-(lower_bound(cur.begin(), cur.end(), qs[c][d]-qs[c][b]-K)-cur.begin());
                cur.emplace_back(qs[c][d]-qs[c][b]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
