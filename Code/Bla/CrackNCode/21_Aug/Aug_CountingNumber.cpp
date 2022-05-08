#include <bits/stdc++.h>
using namespace std;


using ll = long long;

ll a[5],Q,ab,bc,ac,abc,pw[20],pre[20];

///Find the minimum integer N such that its sum of the digit from 1 to N is greater or equal to Q

ll lcm(ll x, ll y){
    return x/__gcd(x, y)*y;
}

ll cal(ll x){
    return (x/a[0])+(x/a[1])+(x/a[2])-(x/ab)-(x/bc)-(x/ac)+(x/abc);
}

void test_case(){
    cin >> a[0] >> a[1] >> a[2] >> Q;
    ab = lcm(a[0], a[1]), bc = lcm(a[1], a[2]), ac = lcm(a[0], a[2]), abc = lcm(a[0], bc);
    for(int i=1; i<=18; i++)
        pre[i] = cal(pw[i]-1); ///It is required to precalculate unless it will TE due to too much division.

    ll l = 1, r = 1e15, ans = 0, kep = 0;
    while(l <= r){
        ll mid = (l+r)/2, now = 0;
        for(int i=1; i<=18; i++){
            if(pw[i]-1 >= mid){
                now += 1ll*i*(cal(mid)-pre[i-1]);
                break;
            }else{
                now += 1ll*i*(pre[i]-pre[i-1]);
            }
        }
        if(now >= Q){
            ans = mid, kep = now;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    while(kep > Q){
        kep--;
        ans /= 10;
    }
    cout << ans%10 << "\n";
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    pw[0] = 1;
    for(int i=1; i<=18; i++)
        pw[i] = pw[i-1]*10;
    while(t--){
        test_case();
    }
    return 0;
}
