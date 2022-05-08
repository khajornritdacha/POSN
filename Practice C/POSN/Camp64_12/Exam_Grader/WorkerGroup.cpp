#include<bits/stdc++.h>
using namespace std;
int a,b,m,n,mn=1e9,ans,K;
main(){
    cin >> K >> m >> n;
    if(m == 0){
        cout << "0 " << K;
        return 0;
    }
    if(n == 0){
        for(int i=1; i<=K; i++){
            int tmp = (m+(i*6)-1)/(i*6);
            if(tmp < mn){
                mn = tmp;
                ans = i;
            }
        }
        cout << ans << " " << K-ans;
        return 0;
    }
    for(int i=1; i<K; i++){
        int ta = (m+(i*6)-1)/(i*6);
        int tb = (n+((K-i)*10)-1)/((K-i)*10);
        if(max(ta, tb) < mn){
            mn = max(ta,tb);
            ans = i;
        }
    }
    cout << ans << " " << K-ans;
}
