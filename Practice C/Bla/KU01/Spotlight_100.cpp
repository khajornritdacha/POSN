#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

int n,ep[1010];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        if(a > b){
            b += 360;
        }
        ep[a]++;
        ep[b]--;
        //cout << a << " " << b << "\n";
    }
    int ans = 0;
    for(int i = 0, now = 0, cur = 0; i <= 720; i++){
        now += ep[i];
        if(now) cur++;
        else cur = 0;
        ans = max(ans, cur);
    }
    if(ans > 360) ans = 360;
    cout << ans << "\n";
    return 0;
}