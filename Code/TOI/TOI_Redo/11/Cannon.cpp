#include <bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;
const int N = 1e6+10;
using ll = long long;

int n,M,T,L,a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M >> T >> L;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]++;
    }

    while(T--){
        int pr = 0, ans = 0;
        for(int i = 1; i <= M; i++){
            int x; cin >> x;
            x++;
            int cr = upper_bound(a+1, a+n+1, x+L)-a-1;
            int cl = lower_bound(a+1, a+n+1, max(1, x-L))-a;

            ans += cr - max(cl-1, pr);

            pr = cr;
        }

        cout << ans << "\n";
    }
    return 0;   
}