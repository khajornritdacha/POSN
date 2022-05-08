#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,K,ans=-2e9,qs[N];

main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        qs[i] = qs[i-1]+x;
    }
    for(int i=K; i<=n; i++){
        ans = max(ans, qs[i]-qs[i-K]);
    }
    cout << ans;
}
