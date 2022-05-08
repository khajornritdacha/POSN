#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,R,nc,nr,ans;
main(){
    cin >> nr >> nc >> R >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        if(abs(nr-x) + abs(nc-y) <= R)
            ans++;
    }
    cout << ans;
}
