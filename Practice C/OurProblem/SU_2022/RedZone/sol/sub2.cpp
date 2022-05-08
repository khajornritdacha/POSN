#include <bits/stdc++.h>
using namespace std;


int main(void) {
    int N, M, L, D; cin >> N >> M >> L >> D;
    int house[N+5] = {};
    int ans = 0;
    set<int> rem;
    for (int i = 1; i <= N; i++) {
        cin >> house[i];
        rem.insert(i);
    }
    for (int i = 1; i <= M; i++) {
        int pos; cin >> pos;
        int l = max(1, pos-L);
        int r = min(N, pos+L);

        while (true) {
            auto it = rem.lower_bound(l);
            if (it == rem.end() or *it > r) break;
            rem.erase(it);
        }
    
        if (ans == 0 and rem.empty()) {
            ans = i;
        }
    }

    if (ans == 0) ans = -1;

    cout << ans << "\n";


    return 0;
}