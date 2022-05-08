#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,a[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int buy = 1e9, ans = 0;
    for(int i=1; i<=n+1; i++){
        if(buy != 1e9 and a[i-1] > a[i] and a[i-1] > buy){
            ans += a[i-1]-buy;
            buy = 1e9;
        }
        if(a[i+1] > a[i] and a[i] < buy){
            buy = a[i];
        }
    }
    cout << ans;
}
