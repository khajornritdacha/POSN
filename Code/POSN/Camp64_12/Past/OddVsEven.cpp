#include<bits/stdc++.h>
using namespace std;
int ee,od;
main(){
    for(int i=1; i<=8; i++){
        int x;
        cin >> x;
        if(x%2 == 0){
            ee+=x;
        }else{
            od+=x;
        }
    }
    if(ee == od)
        cout << "equal";
    else if(ee > od)
        cout << "even";
    else
        cout << "odd";
    cout << "\n";
    cout << ee << "\n" << od;
}
