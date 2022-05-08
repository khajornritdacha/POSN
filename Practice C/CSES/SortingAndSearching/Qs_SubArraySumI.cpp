#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 1e6+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;
using ll = long long;

ll ans;
int n,X;

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> X;
    
    ll cur = 0, ans = 0; //qs(r)-qs(l) = X
    map<int,int> mp; //qs(r)-X = qs(l)
    mp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cur += x;
        ans += mp[cur-X];
        mp[cur]++;
    }
    cout << ans << "\n";
    return 0;
}