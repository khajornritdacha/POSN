#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int ans,cnt,la=1e9,n;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x > la)
            cnt++;
        else
            cnt = 0;
        ans = max(ans, cnt);
        la = x;
    }
    if(ans == 0)
        cout << "No value increase";
    else
        cout << ans;
}
