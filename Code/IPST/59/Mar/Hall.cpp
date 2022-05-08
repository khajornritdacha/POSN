#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10, base = 1e9+7;
using ll = long long;
//https://beta.programming.in.th/tasks/o59_mar_c1_hall
int a[2*N], n;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i+n] = a[i];
    }

    int l = 1, r = n, ans = n+1;
    while(l <= r){
        int mid = (l+r)>>1;

        ll pw = base, cur = 0;
        for(int r = 1; r < mid; r++){
            cur = cur*base + a[r];
            pw *= base;
        }

        bool ok = true;
        set<ll> ss;
        for(int l = 1, r = mid; l <= n; l++, r++){
            cur = cur*base + a[r];
            if(r > mid){
                cur -= pw*a[r-mid];
            }
            if(ss.count(cur)){
                ok = false;
                break;
            }
            ss.insert(cur);
        }

        if(ok){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    if(ans == n+1) ans = 0;
    cout << ans-1 << "\n";
    return 0;
}