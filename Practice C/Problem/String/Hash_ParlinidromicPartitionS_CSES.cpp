#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

ll base = 31, mod = 1e9+7;
char str[N];

///https://cses.fi/165/list/
///greedily split string as soon as the left part and right part are the same

void test_case(){
    cin >> (str+1);
    int n = strlen(str+1);
    ll hl = 0, hr = 0, pw = 1, ans = 0, l = 1, r = n;
    for(int lim = n/2 ; l <= lim; l++, r--){
        hl = (hl*base + 1ll*str[l]-'a'+1)%mod;
        hr = (hr + 1ll*(str[r]-'a'+1)*pw)%mod;
        pw = (pw*base)%mod;
        if(hl == hr){
            ans += 2;
            hl = hr = 0;
            pw = 1;
        }
    }

    if(n&1 and hl == 0 and hr == 0) ans++;
    else if(hl != 0) ans++;

    cout << ans << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
