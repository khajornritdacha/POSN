#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

lb sum,ep=0.00000001;
int n,a[N];

bool chk(lb val){
    lb mx,cur;
    mx = cur = a[2]-val;
    for(int i=3; i<n; i++){
        if(cur < 0)
            cur = 0;
        cur += a[i]-val;
        mx = max(mx, cur);
    }
    return (mx+n*val >= sum);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); freopen("sabotage.in", "r", stdin); freopen("sabotage.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
    lb  l = 1, r = 1e9, mid, ans;
    while(r-l > ep){
        mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << setprecision(3) << fixed << ans << "\n";
}
