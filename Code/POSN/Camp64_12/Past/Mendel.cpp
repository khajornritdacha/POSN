#include<bits/stdc++.h>
using namespace std;
int t,n;
main(){
    cin >> t >> n;
    if(t == 1 or t == 2 or t == 3){
        cout << n << " 0";
    }else if(t == 4){
        cout << "0 " << n;
    }else if(t == 5){
        cout << n/2 << " " << n/2;
    }else{
        cout << n*3/4 << " " << n/4;
    }
}
