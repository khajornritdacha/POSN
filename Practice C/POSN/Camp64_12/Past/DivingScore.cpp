#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,sum,mx,mn=1e9;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
        sum += x;
    }
    if(n > 3)
        cout << sum-mx-mn;
    else
        cout << sum;
}
