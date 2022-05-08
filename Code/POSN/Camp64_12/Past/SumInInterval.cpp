#include<bits/stdc++.h>
using namespace std;
int y,sum,x;
bool ok;
main(){
    cin >> x >> y;
    for(int i=1; i<=8; i++){
        int z;
        cin >> z;
        if(x <= z and z <= y){
            sum+=z;
            ok = true;
        }
    }
    if(!ok)
        cout << "None";
    else
        cout << sum;
}
