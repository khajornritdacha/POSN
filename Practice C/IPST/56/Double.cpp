#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,a[N],qs[N];

main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
    }
    if(qs[n]%2 != 0){
        cout << "NO\n";
        return 0;
    }
    for(int i=1; i<=n; i++){
        if(qs[i]*2 == qs[n]){
            cout << i << "\n";
            return 0;
        }
    }

    for(int i=1; i<=n; i++){
        int l=1,r=n-i+1,mid,ans = -1;
        while(l <= r){
            mid = (l+r)/2;
            if(qs[i+mid-1]-qs[i-1] == qs[n]/2){
                ans = mid;
                break;
            }else if(qs[i+mid-1]-qs[i-1] < qs[n]/2){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        if(ans != -1){
            cout << i-1 << " " << i+mid-1;
            return 0;
        }
    }
    cout << "NO\n";
}
