#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

ll n,mod = 1e9+7;

main(void){
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; ){
        ll l = i, r = n/(n/i), rr = r; //the last number(r) that quotient(q) remains the same = n/q
        //ans += q*(sum(l...r)) because all of the numbers in range [l..r] appears exactly q times

        ll num = r-l+1, val = l+r; //compute sum(l...r)
        if(num % 2 == 0) num /= 2; //the number of elements in range [l...r] is even then sum = (l+r)*(r-l+1)/2 --> (first + last) * (number of elements divided by two)
        else val /= 2; //the number of elements in rage [l...r] is odd then sum = (l+r)/2 * (r-l+1) --> (first+last)/2 = the middle elements, and mutiplies it by the number of elements

        num %= mod, val %= mod;
        ll sum = (n/i)%mod*num%mod*val%mod;

        ans = (ans + sum)%mod;
        i = rr+1;
    }
    cout << ans << "\n";
}