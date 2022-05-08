#include<bits/stdc++.h>
using namespace std;
int n,ans[10],la=1e9;
main(){
    while(true){
        int x;
        cin >> x;
        if(x != 0 and x != 1)
            break;
        if(x == 0 and la == 0)
            ans[0]++;
        else if(x == 0 and la == 1)
            ans[2]++;
        else if(x == 1 and la == 0)
            ans[1]++;
        else if(x == 1 and la == 1)
            ans[3]++;
        la = x;
    }
    for(int i=0; i<4; i++){
        cout << ans[i] << "\n";
    }
}
