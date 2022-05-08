#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
using ll = long long;

ll n,a[N],b[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll l = 0, r = 1e18, ans = -1, k = 0;
    while(l <= r){
        ll mid = (l+r)>>1;
        k = 0;
        //cout << mid << "\n";
        for(int i = 1; i <= n; i++){
            if(a[i] > mid){
                b[++k] = a[i];
            }
        }

        bool ok = true;
        int la = b[1], num = 1;
        for(int i = 2; i <= k; i++){
            if(b[i] != la and num == 1){
                ok = false;
                break;
            }else if(b[i] == la){
                num = 0;
            }else if(num == 0){
                num++;
                la = b[i];
            }
        }

        /*for(int i = 1; i <= k; i++){
            cout << b[i] << " \n"[i==k];
        }*/

        if(ok){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }

    cout << ans << "\n";

    return 0;
}
