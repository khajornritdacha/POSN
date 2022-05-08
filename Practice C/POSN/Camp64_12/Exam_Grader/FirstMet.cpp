#include<bits/stdc++.h>
using namespace std;
int a,b;
bool ok;
main(){
    cin >> a >> b;
    while(!ok){
        int x;
        cin >> x;
        if(x < 0){
            if(!ok)
                cout << x;
            break;
        }
        if(!ok and x%a == 0 and x%b == 0){
            cout << x << "\n" << 2;
            ok = true;
        }else if(!ok and x%a == 0){
            cout << x << "\n" << 0;
            ok = true;
        }else if(!ok and x%b == 0){
            cout << x << "\n" << 1;
            ok = true;
        }
    }
}
