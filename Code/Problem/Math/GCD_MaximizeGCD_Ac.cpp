#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
using ll = long long;

///https://atcoder.jp/contests/arc126/tasks/arc126_c

vector<ll> cal(vector<ll> vec){
    vector<ll> res(vec.size());
    for(int i = 1; i < vec.size(); i++){
        res[i] = res[i-1]+vec[i];
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,K,mx = 0;
    cin >> n >> K;
    vector<ll> cn(N), su(N);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cn[x]++, su[x] += x;
        mx = max(mx, 1ll*x);
    }

    auto cumc = cal(cn);
    auto cums = cal(su);

    ll ans = 1;
    for(int x = 2; x < mx; x++){
        ll l = 0, r = x;
        ll k = 0;
        while(l < mx){
            ll tmps = cums[min(mx, r)]-cums[l];
            ll tmpc = cumc[min(mx, r)]-cumc[l];
            k += tmpc*r-tmps;
            l += x, r += x;
        }
        //cout << "X " << x << " = " << k << "\n";
        if(k <= K)
            ans = x;
    }

    /*for(int i = 0; i <= 10; i++){
        cout << cums[i] << " ";
    }
    cout << cums[mx] << "\n";*/

    if(K >= n*mx-cums[mx]){
        ans = mx+(K-n*mx+cums[mx])/n;
    }

    cout << ans << "\n";

    return 0;
}
