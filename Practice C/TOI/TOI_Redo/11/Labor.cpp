#include <bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;
const int N = 1e6+10;
using ll = long long;

int n,a[N];
ll K;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }    

    ll l = 1, r = 1e18, ans = -1;
    while(l <= r){
        ll mid = (l+r)>>1, tmp = 0;
        for(int i = 1; i <= n; i++){
            tmp += mid/a[i];
        }
        if (tmp >= K) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << ans << "\n";
    return 0;   
}