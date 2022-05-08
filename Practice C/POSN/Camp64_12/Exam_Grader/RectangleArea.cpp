#include<bits/stdc++.h>
using namespace std;
double w,h;
main(){
    cin >> w >> h;
    if(w <= 0 and h <= 0){
        cout << "invalid width and height";
    }else if(w <= 0){
        cout << "invalid width";
    }else if(h <= 0){
        cout << "invalid height";
    }else{
        cout << setprecision(2) << fixed << w*h;
    }
}
