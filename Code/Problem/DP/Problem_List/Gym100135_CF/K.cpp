#include<bits/stdc++.h>
using namespace std;
int n,k;
main(){
    freopen("joseph.in","r",stdin);
    freopen("joseph.out","w",stdout);
    cin >> n >> k;
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = (ans+k)%i;
    }
    cout << ans+1;
}
