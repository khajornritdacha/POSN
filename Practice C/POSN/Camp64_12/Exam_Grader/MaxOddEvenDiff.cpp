#include<bits/stdc++.h>
using namespace std;
int od,ev;
main(){
    while(true){
        int x;
        cin >> x;
        if(x <= 0)
            break;
        if(x%2)
            od = max(od, x);
        else
            ev = max(ev, x);
    }
    cout << od << "\n" << ev << "\n"  << abs(od-ev);
}
