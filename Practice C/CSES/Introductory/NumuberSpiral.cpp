#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int Q;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Q;
    while(Q--){
        ll R,C;
        cin >> R >> C;
        ll mx = max(R, C);
        if(mx%2 == 0){
            if(mx == R){
                cout << mx*mx-C+1;
            }else{
                cout << (mx-1)*(mx-1)+R;
            }
        }else{
            if(mx == R){
                cout << (mx-1)*(mx-1)+C;
            }else{
                cout << mx*mx-R+1;
            }
        }
        cout << "\n";
    }
    return 0;
}
