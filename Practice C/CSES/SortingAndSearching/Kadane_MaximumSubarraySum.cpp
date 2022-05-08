#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 1e6+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;
using ll = long long;

ll INF = 1e18;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll cur = -INF, ans = -INF;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cur = max(cur+x, 1ll*x);
        ans = max(ans, cur);
    }    
    cout << ans << "\n";
    return 0;
}