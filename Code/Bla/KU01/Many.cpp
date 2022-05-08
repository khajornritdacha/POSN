#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e5+10;

int n,K,a[N],type,cnt[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    for(int l = 1, r = 0; l <= n; l++){
        while(r <= n and type < K){
            r++;
            if(++cnt[a[r]] == 1){
                type++;
            }
        }
        ans += 1ll*n-r+1;
        if(--cnt[a[l]] == 0){
            type--;
        }
    }
    cout << ans << "\n";
    return 0;
}
