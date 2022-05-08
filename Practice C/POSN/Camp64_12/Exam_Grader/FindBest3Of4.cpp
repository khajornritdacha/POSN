#include<bits/stdc++.h>
using namespace std;
int sum,mn=1e9,ans;
main(){
    while(true){
        sum = 0, mn = 1e9;
        for(int i=1; i<=4; i++){
            int x;
            cin >> x;
            if(x < 0){
                cout << ans;
                return 0;
            }
            sum+=x;
            mn = min(mn, x);
        }
        ans = max(ans, sum-mn);
    }
}
