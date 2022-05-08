#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,a[N],ans;

main(){
    cin >> n;
    for(int i=1; i<=2*n; i++){
        cin >> a[i];
    }
    sort(a+1, a+2*n+1);
    for(int i=1; i<=2*n; i+=2){
        ans += a[i+1]-a[i];
    }
    cout << ans;
}
