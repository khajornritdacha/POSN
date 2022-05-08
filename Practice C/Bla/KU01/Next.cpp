#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;

int n,a[N];
bool vi[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int mx = 0;
    for(int i = 1; i <= n; i++){
        if(vi[i]) continue;
        vi[i] = true;
        int sz = 1;
        int u = a[i];
        while(u != i){
            sz++;
            vi[u] = true;
            u = a[u];
        }
        mx = max(mx, sz);
    }

    cout << mx << "\n";
    return 0;
}
