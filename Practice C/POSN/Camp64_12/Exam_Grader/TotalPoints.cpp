#include<bits/stdc++.h>
using namespace std;

int n,a[1010],ans;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,val;
        cin >> x >> val;
        a[x] = max(a[x], val);
    }
    for(int i=1; i<=13; i+=2){
        ans += a[i];
    }
    cout << ans;
}
