#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

ll n,a[N];

int main(void){
    cin >> n;
    int ans = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 2; i <= n; i++){
        if(a[i] != a[i-1])
            ans++;
    }
    cout << ans << "\n";
    return 0;
}
