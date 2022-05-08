#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

ll n,pw[N],mod = 1e9+7;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    pw[0] = 1;
    for(int i = 1; i <= n; i++){
        pw[i] = (pw[i-1]*2)%mod;
    }
    cout << pw[n];
    return 0;
}
