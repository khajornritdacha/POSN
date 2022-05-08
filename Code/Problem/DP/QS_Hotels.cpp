#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
using ll = long long;

///https://www.spoj.com/problems/HOTELS/
/// 6 Nov 2021

int n;
ll M,qs[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M;
    for(int i = 1; i <= n; i++){
        cin >> qs[i];
        qs[i] += qs[i-1];
       // cout << qs[i] << " ";
    }
    set<ll> ss = {0};
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        auto it = ss.lower_bound(qs[i]-M);
        //cout << "I : " << i << " = " << qs[i] << " " << *it << "\n";
        ans = max(ans, qs[i]-(*it));
        ss.insert(qs[i]);

        /*cout << "==========\n";
        for(int s : ss) cout << s << " ";
        cout << "\n";*/
    }
    cout << ans << "\n";
    return 0;
}
