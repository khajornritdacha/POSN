#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

ll n,a[N],qs[N];

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    a[n+1] = 1e18;
    for(int i = 1; i <= n+1; i++){
        qs[i] = qs[i-1]+a[i];
        if(a[i] > qs[i-1]+1){
            cout << qs[i-1]+1 << "\n";
            return 0;
        }
    }
    return 0;
}
