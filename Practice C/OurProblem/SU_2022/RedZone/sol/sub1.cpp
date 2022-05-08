#include <bits/stdc++.h>
using namespace std;


int main(void) {
    int N, M, L, D; cin >> N >> M >> L >> D;
    int house[N+5] = {};
    int destroyed = 0, ans = 0;

    for (int i = 1; i <= N; i++) {
        cin >> house[i];
    }


    for (int i = 1; i <= M; i++) {
        int pos; cin >> pos;
        int l = max(1, pos-L);
        int r = min(N, pos+L);

        for (int j = l; j <= r; j++) {
            if (house[j] > 0 and house[j]-D <= 0) {
                destroyed++;
            }
            house[j] -= D;
        }

        if (destroyed == N and ans == 0) {
            ans = i;
        }
    }

    if (ans == 0) ans = -1;
    cout << ans << "\n";

    return 0;
}