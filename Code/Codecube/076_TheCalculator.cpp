#include<bits/stdc++.h>
using namespace std;


main(){
    long double a,b,c;
    cin >> a >> b >> c;
    if(abs(c-a-b) <= 0.00000000001){
        cout << "Correct";
    }else{
        cout << "Wrong";
    }
}
