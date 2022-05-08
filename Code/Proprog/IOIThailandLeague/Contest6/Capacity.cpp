#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+10;
int n,mod=49999,a[N];
long long ans,mul;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    mul = 1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=4; i<=n; i++){
        mul = (mul*(i-2))%mod;
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ans += ((a[j]-a[i])*mul);
        }
    }
    cout << ans%mod;
}
