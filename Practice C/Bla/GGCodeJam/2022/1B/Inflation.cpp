#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int N = 1010;

int n, P;
ll ex[N][2], dp[N][2];

ll cost(int i1, int c1, int i2, int c2) {
    return abs(ex[i1][c1]-ex[i2][c2]);
}

void test_case(){
    cin >> n >> P;
    for (int i = 1; i <= n; i++) {
        ex[i][0] = INF, ex[i][1] = -INF;
        for (int j = 1; j <= P; j++) {
            ll x; cin >> x;
            ex[i][0] = min(ex[i][0], x);
            ex[i][1] = max(ex[i][1], x);
        }
        dp[i][0] = dp[i][1] = INF;
    }

    ex[0][0] = ex[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int e : {0, 1}) {
            for (int k : {0, 1}) {
                dp[i][e] = min(dp[i][e], dp[i-1][k] + cost(i-1, k, i, !e) + ex[i][1]-ex[i][0]);
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        test_case();
        cout << "\n";
    }

    return 0;
}