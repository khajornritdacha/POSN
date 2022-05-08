#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+10;
int n,K,x[N],f[N];
int over(int p){
    if(p<=0) return 0;
    if(p%2 == 0)
        return (p/2)*(p/2+1);
    return ((p+1)/2)*((p+1)/2);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> x[i];
    }
    sort(x+1, x+n+1);
    int l=0, r=1e9, ans=1e9, mid;
    while(l<=r){
        mid = (l+r)/2;
        int ri = x[1]+mid,le;
        int now = (mid+1)*(mid+1);
        for(int i=2; i<=n; i++){
            le = x[i]-mid;
            int range = ri-le+1;
            now+=(mid+1)*(mid+1)-over(range);
            ri = x[i]+mid;
        }
        //cout << now << " " << mid << "\n";
        if(now >= K){
            ans = min(ans, mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
