#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,a[N],mod=2553,ans;
main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0, cnt=n; i<n; i++,cnt--){
        ans += (((1ll*cnt*(cnt+1)/2)%mod)*a[i])%mod;
        ans %= mod;
    }
    cout << ans;
}
