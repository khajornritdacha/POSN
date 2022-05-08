#include<bits/stdc++.h>
using namespace std;

main(){
    for(int i=1; i<=7; i++){
        int wa,su;
        cin >> wa >> su;
        int ans = min(wa/250, su/15);
        cout << ans;
        if(wa-ans*250 > 0)
            cout << " water";
        cout << "\n";
    }
}
