#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using lb = long double;
using ll = long long;
int n,C;
ll xs[N],ys[N],xd[N],yd[N],mn[N];

main(){
    cin >> n >> C;
    for(int i=1; i<=n; i++){
        cin >> xs[i] >> ys[i];
        mn[i] = 6e18;
    }

    for(int i=1; i<=C; i++){
        cin >> xd[i] >> yd[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=C; j++){
            mn[i] = min(mn[i], (xs[i]-xd[j])*(xs[i]-xd[j])+(ys[i]-yd[j])*(ys[i]-yd[j]));
        }
    }

    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, mn[i]);
    }
    cout << setprecision(4) << fixed << sqrt(1.0*ans) << "\n";
}
