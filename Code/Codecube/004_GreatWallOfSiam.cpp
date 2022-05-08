#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
int n,g,a[N];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += a[i]/g;
    }
    cout << ans;
}
