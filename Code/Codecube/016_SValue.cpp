#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e3+10;

int n;
long long ans,a[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=2*n; i++){
        cin >> a[i];
    }
    sort(a+1, a+2*n+1);
    for(int i=1, j=2*n; i<=j; i++,j--){
        ans += a[i]*a[j];
    }
    cout << ans << "\n";
}
