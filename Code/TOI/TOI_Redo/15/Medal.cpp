#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

int n,a[N],h[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    sort(a+1, a+n+1, greater<int>());
    sort(h+1, h+n+1);

    for(int i = 1; i <= n; i++){
        a[i] += h[i];
    }
    sort(a+1, a+n+1);

    long long ans = 0;
    for(int i = 2; i <= n; i++){
        ans += a[i]-a[i-1];
    }
    cout << ans << "\n";

    return 0;
}
