#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4+10;
ll num[N],a[N],tmp,n,ans,mod = 49999;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    num[3] = 1;
    for(ll i=4; i<=1e4; i++){
        num[i] = (num[i-1]*(i-2))%mod;
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    if(n==2) return cout << a[2]-a[1] << "\n", 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            tmp = a[j]-a[i];
            ans+=tmp;
        }
    }
    ans%=mod;
    cout << (ans*num[n])%mod << "\n";
}
