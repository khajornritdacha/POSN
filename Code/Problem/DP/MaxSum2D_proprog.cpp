#include<bits/stdc++.h>
using namespace std;
int n,a[150][150],now,ans,pre;
main(){
    while(cin >> n){
    ans=-2e9;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i1=1; i1<=n; i1++){
        int chua[n+5];
        memset(chua,0,sizeof(chua));
        for(int i2=i1; i2<=n; i2++){
            pre=now=0;
            for(int j=1; j<=n; j++){
                chua[j]+=a[i2][j];
                now=max(chua[j],pre+chua[j]);
                ans=max(now,ans);
                pre=now;
            }
        }
    }
    cout << ans << "\n";
    }
}
