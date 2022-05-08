// In this subtask, we will define set "rem" to contain houses that have not destroyed 
// Then, process each bomb in order by binary search(set.lower_bound) to check whether the set still has any house that
// its position is in range [pos-L, pos+L] if yes, then that element is removed and repeat this process until
// none of element in the set is in range [pos-L, pos+L]
// Runtime: O((N+M)logN)

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