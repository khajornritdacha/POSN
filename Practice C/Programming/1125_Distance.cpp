#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+10;
ll ansx, ansy;
int n,x[N],y[N];
///write in expression form x1-x2 + x1-x3 + ... + y1-y2 + y1-y3 + ... = ans
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin  >> n;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    sort(x, x+n, greater<int>());
    sort(y, y+n, greater<int>());
    for(ll i=0; i<n; i++){
        ansx-=(x[i]*i);
        ansy-=(y[i]*i);
        ansx+=(x[i]*(n-i-1));
        ansy+=(y[i]*(n-i-1));
    }
    cout << ansx+ansy << "\n";
}
