#include<bits/stdc++.h>
using namespace std;
int sum,mn=1e9,ans,mxid,cntmx;
main(){
    while(true){
        int id;
        sum = 0, mn = 1e9;
        cin >> id;
        if(id < 0){
            if(cntmx > 1)
                cout << cntmx << "*\n";
            else
                cout << mxid << "\n";
            cout << ans;
            return 0;
        }
        for(int i=1; i<=4; i++){
            int x;
            cin >> x;
            sum+=x;
            mn = min(mn, x);
        }
        if(sum-mn > ans){
            ans = sum-mn;
            mxid = id;
            cntmx = 1;
        }else if(sum-mn == ans){
            cntmx++;
        }
    }
}
