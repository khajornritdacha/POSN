#include<bits/stdc++.h>
using namespace std;
int n,ans=1e9;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y,r;
        cin >> x >> y >> r;
        ans = min(ans, abs(y)-r);
    }
    if(ans <= 0)
        ans = -1;
    cout << ans;
}
