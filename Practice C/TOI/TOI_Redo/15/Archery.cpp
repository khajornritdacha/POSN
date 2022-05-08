#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

struct DATA{
    int p,h;
};

int n;
DATA a[N];
ll sumr[N],mn = 1e18,ans,min_height = 1e18;

 main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].h;
        min_height = min(min_height, 1ll*a[i].h);
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].p;
    }

    sort(a+1, a+n+1, [&](const DATA &A, const DATA &B){
        if(A.p != B.p) return A.p < B.p;
        return A.h < B.h;
    });

    for(int i = n; i >= 1; i--){
        sumr[i] = sumr[i+1]+a[i].p-1;
    }

    /*for(int i = 1; i <= n; i++) cout << a[i].p << " " << a[i].h << "\n";
    cout << "\n";*/

    ll nlf = 0, tsp = 0, num_left = 0, sum_pos = 0;
    for(int i = 1; i <= n; i++){
        if(a[i].p > min_height) break;
        ll lef = sum_pos - 1ll*num_left*a[i].p;
        ll rig = sumr[i+1]-1ll*(n-i)*(a[i].p-1);

        //cout << "I : " << i << " = " << lef << " " << rig << "\n";
        //cout << "LEFT : " << sum_pos << " " << num_left << " " << a[i].p << "\n";
        if(lef+rig < mn){
            mn = lef+rig;
            ans = a[i].p;
        }
        nlf++, tsp += a[i].p+a[i].h;
        if(a[i].p != a[i+1].p){
            num_left += nlf;
            sum_pos += tsp;
            nlf = tsp = 0;
        }
    }
    cout << ans << " " << mn << "\n";
    return 0;
}
