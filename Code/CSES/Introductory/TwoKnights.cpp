#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
using ll = long long;

int n;
ll num[N],ans[N];

int main(void){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        num[i] = i*i-(i-1)*(i-1);
        //cout << num[i] << " ";
    }
   // cout << "\n";
    ans[1] = 0; ans[2] = 6; ans[3] = 28; ans[4] = 96;

    for(int i = 5, Z = 9; i <= n; i++, Z+=2){
        ll K0 = 1ll*(i-3)*(i-3)*num[i];
        ll K1 = 2*(num[i]-1) + (num[i]-4) + (num[i-2]-3)*(num[i]-2);
        ll K2 = 4*(num[i]-1) + 2*(num[i]-3) + (num[i-1]-6)*(num[i]-2);
        ll K3 = ((num[i]-1)*num[i])/2 - 2;
        //cout << 4*(num[i]-1) << " " << 2*(num[i]-3) << " " << (num[i-1]-6)*(num[i]-2) << "\n";
        //K3 /= 2;
        //cout << "I " << i << " = " << K0 << " " << K1 << " " << K2 << " " << K3 << "\n";
        ans[i] = K0+K1+K2+K3+ans[i-1]+num[i]-Z;
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
