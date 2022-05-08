#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int qs[N],a[N],n,Q;

int sum(int l, int r){
    if(l > r) return 0; ///[5, 2]
    if(l-1 < 0) return qs[r]; ///[-1, 5]
    return qs[r]-qs[l-1];
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
    }
    cin >> Q;
    while(Q--){
        int l,r; cin >> l >> r;
        cout << sum(l, r) << "\n";
    }
    return 0;
}

/*
5
1 -3 5 -10 7
3
-1 3
2 4
50 1
*/
