#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 1e6+10, INF = 1e9;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,a[N];
ll qs[N], K;

void test_case(){
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater<int>());

    for(int i = 1; i <= n; i++){
        qs[i] = qs[i-1] + a[i];
    }

    ll ans = 0;
    for(int i = 1; i*K <= n; i++){
        ans = max(ans, qs[i*K] - qs[i*K-i]);
    }
    cout << ans << "\n";
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
