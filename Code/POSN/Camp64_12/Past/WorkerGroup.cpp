#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int K,b,s,ans,mn=1e9;
main(){
    cin >> K >> b >> s;
    if(b == 0){
        cout << "0 " << K;
        return 0;
    }
    if(s == 0){
        for(int i=1; i<=K; i++){
            if((b+i*6-1)/(i*6) < mn){
                mn = (b+i*6-1)/(i*6);
                ans = i;
            }
        }
        cout << ans << " " << K-ans;
        return 0;
    }
    for(int i=1; i<K; i++){
        int d1 = (b+i*6-1)/(i*6);
        int d2 = (s+(K-i)*10-1)/((K-i)*10);
        if(max(d1, d2) < mn){
            mn = max(d1, d2);
            ans = i;
        }
    }
    cout << ans << " " << K-ans;
}
