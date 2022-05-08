#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

int n, m,a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }

    if(n < m){ cout << "-1\n"; return 0; }

    ll l = 1, r = 1e9, ans = -1;
    while(l <= r){
        ll mid = (l+r)>>1, tmp = 0;

        for(int i = 1; i <= m; i++){
            tmp += (a[i]+mid-1)/mid;
        }
        if(tmp <= n){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << "\n";

    return 0;
}