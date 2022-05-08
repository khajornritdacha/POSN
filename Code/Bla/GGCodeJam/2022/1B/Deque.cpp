#include <bits/stdc++.h>
using namespace std;


const int N = 1e5+10;

int arr[N], ans, mx, n;

void sell(int idx) {
    if(arr[idx] >= mx) {
        ans++;
        mx = arr[idx];
    }
}

void test_case() {
    ans = 0, mx = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(int l = 1, r = n; l <= r; ) {
        if(arr[l] <= arr[r]) {
            sell(l);
            l++;
        } else {
            sell(r);
            r--;
        }
    }
    cout << ans;
    return;
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