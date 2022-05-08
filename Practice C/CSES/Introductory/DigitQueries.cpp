#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll pw[20],qs[20];

int main(void){
    pw[0] = 1;
    for(int i = 1; i <= 17; i++){
        pw[i] = pw[i-1]*10;
        qs[i] = qs[i-1]+(pw[i]-pw[i-1])*i;
        //cout << qs[i] << " ";
    }
    int Q; cin >> Q;
    while(Q--){
        ll K; cin >> K;
        int C = 1;
        while(K > qs[C]) C++;
        K -= qs[C-1];
        ll l = pw[C-1], r = pw[C]-1, mn = 2e18, res = -1;
        while(l <= r){
            ll mid = (l+r)>>1;
            ll Bval = (mid-pw[C-1]+1)*C;
            if(Bval >= K){
                mn = Bval;
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        while(mn > K){
            mn--;
            res /= 10;
        }
        cout << res%10 << "\n";
    }
    return 0;
}
