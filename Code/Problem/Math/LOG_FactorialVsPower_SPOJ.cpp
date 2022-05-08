#include <bits/stdc++.h>
using namespace std;

const int lim = 3e6, N = lim+10;
using lb = long double;

lb fac[N], eps = 1e-8;

///https://www.spoj.com/problems/FACVSPOW/
///take log to change from multiplication into addition

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= lim; i++){
        fac[i] = fac[i-1]+log(i);
    }

    //cout << eps << "\n";
    int Q; cin >> Q;
    while(Q--){
        int a; cin >> a;
        int l = 1, r = lim, ans = -1;
        while(l <= r){
            int mid = (l+r)>>1;
            //cout << mid << "\n";
            //cout << setprecision(5) << fixed << fac[mid] << " " << (lb)mid*log(a) << "\n";
            if(fac[mid]-(lb)mid*log(a) > eps){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
