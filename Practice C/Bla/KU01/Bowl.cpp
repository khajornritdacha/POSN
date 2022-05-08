#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

using ll = long long;
const int N = 1e5+10;

int n,cnt[310];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cnt[x]++;
        ans = max(ans, cnt[x]);
    }

    cout << ans << "\n";
    return 0;
}
