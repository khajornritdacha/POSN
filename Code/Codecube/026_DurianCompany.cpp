#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,ep[N],mx;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        ep[x]++;
        ep[y]--;
    }
    for(int i=0; i<=1e6; i++){
        if(i != 0)
            ep[i] += ep[i-1];
        mx = max(mx, ep[i]);
    }
    cout << mx;
}
