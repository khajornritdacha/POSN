#include<bits/stdc++.h>
using namespace std;

int n,a[10010],sum,mx,K;

main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(i >= K)
            sum -= a[i-K];
        sum += a[i];
        mx = max(mx, sum);
    }
    cout << mx;
}
