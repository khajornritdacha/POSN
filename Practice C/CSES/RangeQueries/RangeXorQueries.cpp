#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, Q; cin >> n >> Q;
    int qs[n+5] = {};
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        qs[i] = qs[i-1]^x;
    }

    while(Q--){
        int a, b; cin >> a >> b;
        cout << (qs[b]^qs[a-1]) << "\n";
    }

    return 0;
}