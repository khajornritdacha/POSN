#include<bits/stdc++.h>
using namespace std;
int l,n,ep[500],sum,ans;
main(){
    cin >> l >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        ep[x]++;
        ep[y]--;
    }
    for(int i=0; i<=l; i++){
        sum+=ep[i];
        ans=max(ans,sum);
    }
    cout << ans;
}
