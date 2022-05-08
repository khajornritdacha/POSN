#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int ans = 2e15,n,T,a[N];
main(){
    cin >> n >> T;
    T-=n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    long long l=0,r=2e15,mid;
    while(l<=r){
        mid = (l+r)/2;
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += mid/a[i];
        }
        if(sum >= T){
            ans = min(1ll*ans, mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans;
}
