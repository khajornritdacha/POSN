#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n,m,K;

///https://codeforces.com/problemset/problem/448/D

int main(void){
    cin >> n >> m >> K;

    ll l = 1, r = n*m, ans = -1;

    while(l <= r){
        ll mid = (l+r)>>1, cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += min(mid/i, m);
        }
        if(cnt >= K){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
