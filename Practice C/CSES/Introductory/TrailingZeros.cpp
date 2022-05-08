#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

ll n,ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n){
        ans += n/5;
        n /= 5;
    }
    cout << ans << "\n";
    return 0;
}
