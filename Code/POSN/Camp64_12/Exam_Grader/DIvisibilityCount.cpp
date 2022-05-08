#include<bits/stdc++.h>
using namespace std;
int a,b,ans[3];
bool ok;
string fi;
main(){
    cin >> a >> b;
    while(true){
        int x;
        cin >> x;
        if(x <= 0){
            break;
        }
        if(x%a == 0 and x%b == 0){
            ans[0]++; ans[1]++;
            if(!ok)
                fi = "xy";
            ok = true;
        }else if(x%a == 0){
            ans[0]++;
            if(!ok)
                fi = "x";
            ok = true;
        }else if(x%b == 0){
            ans[1]++;
            if(!ok)
                fi = "y";
            ok = true;
        }
    }
    cout << ans[0] << "\n" << ans[1] << "\n" << fi;
}
