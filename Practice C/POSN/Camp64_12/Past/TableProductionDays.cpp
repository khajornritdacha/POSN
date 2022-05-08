#include<bits/stdc++.h>
using namespace std;
int wb,wws,ob,os;

main(){
    cin >> wb >> wws >> ob >> os;
    if(ob != 0 and wb == 0 or os != 0 and wws == 0){
        cout << "Unable to finish order\n";
        return 0;
    }
    if(ob == 0){
        cout << (os+(wws*10)-1)/(wws*10);
    }else if(os == 0){
        cout << (ob+(wb*6)-1)/(wb*6);
    }else{
        cout << max((ob+(wb*6)-1)/(wb*6), (os+(wws*10)-1)/(wws*10));
    }
}
