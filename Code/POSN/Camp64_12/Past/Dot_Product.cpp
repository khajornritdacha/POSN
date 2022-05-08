#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,a[N],b[N],ans;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
        ans += (a[i]*b[i]);
    }
    cout << ans;
}

