// Sqrt decomposition (Precalculate sum for m <= sqrt(n), otherwise loops to get sum)
// Author: JO
// Date: 6/5/2022

#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5+10;
const int MXSQ = 320;
int qs[MXSQ][MXN] = {}, SQ;

void PreProcess(int N, vector<int> arr) {
    SQ = 1+sqrt(N);
    for (int sz = 1; sz <= SQ; sz++) {
        for (int i = 1; i <= N; i++) {
            qs[sz][i] = qs[sz][max(0, i-sz)] + arr[i];
        }
    }
}

int get_sum(int l, int m, int r) {
    int k = (r-l)/m;
    return qs[m][l+m*k] - qs[m][max(0, l-m)];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    vector<int> arr(N+5);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    PreProcess(N, arr);

    while (Q--) {
        int l, m, r; cin >> l >> m >> r;

        if (m <= SQ) {
            cout << get_sum(l, m, r) << " ";
        } else {
            int sum = 0;
            for (int i = l; i <= r; i += m) sum += arr[i];
            cout << sum << " ";
        }
    }

    return 0;
}