#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int n,a[N][N];
long long ans = 0;

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1, k = n; j <= n/2; j++, k--){
            ans += 1ll*a[i][j]*(k-j);
        }
        for(int j = n/2+1, k = 1; j <= n; j++, k++){
            ans += 1ll*a[i][j]*(j-k);
        }
    }
    cout << ans << "\n";
    return 0;
}
