#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,qs[N],a[N];

int sum(int l, int r){
    if(r > l) return 0;
    if(l-1 < 0) return qs[r];
    return qs[r]-qs[l-1];
}


main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
    }
    /*for(int i=1; i<=n; i++){
        cout << i%10 << " ";
    }
    cout << "\n";*/
    for(int i=1; i<=n; i++){
        cout << qs[i] << " ";
    }
    cout << '\n';

    int Q;
    cin >> Q;
    while(Q--){
        int l,r;
        cin >> l >> r;
        cout << sum(l, r) << "\n";
    }
}
