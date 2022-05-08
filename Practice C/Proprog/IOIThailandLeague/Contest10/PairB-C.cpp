#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;
int n,a[N];
ll pre[N],suf[N],mn=1e18;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=2*n+1; i++){
        cin >> a[i];
    }
    sort(a+1, a+2*n+2);
    for(int i=2; i<=2*n+1; i+=2){
        pre[i] = pre[i-2]+a[i]-a[i-1];
    }
    for(int i=2*n; i>=1; i-=2){
        suf[i] = suf[i+2]+a[i+1]-a[i];
    }
    for(int i=1; i<=2*n+1; i++){
        if(i%2)
            mn = min(mn, pre[i-1]+suf[i+1]);
        else
            mn = min(mn, pre[i-2]+a[i+1]-a[i-1]+suf[i+2]);
    }
    cout << mn;
}
