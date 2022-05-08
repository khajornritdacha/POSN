#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long ans,pw;
int n,x[N],y[N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    sort(x+1, x+n+1, greater<int>());
    sort(y+1, y+n+1, greater<int>());
    pw = n-1;
    for(int i=1; i<=n; i++,pw-=2){
        ans += x[i]*pw+y[i]*pw;
    }
    cout << ans;
}
