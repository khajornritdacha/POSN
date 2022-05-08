#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=1e18;
main(){
    cin >> n;
    int l=1,r=1e18,mid;
    while(l<=r){
        mid = (l+r)/2;
        int point = (mid/7*23) + (mid/7/12*98);
        if(point >= n){
            ans = min(ans, mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
