#include<bits/stdc++.h>
using namespace std;
int n;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(x == y and x == z){
            cout << "xyz";
        }else if(x == y){
            cout << "xy";
        }else if(x == z){
            cout << "xz";
        }else if(y == z){
            cout << "yz";
        }else if(x > y and x > z){
            cout << "x";
        }else if(y > x and y > z){
            cout << "y";
        }else if(z > x and z > y){
            cout << "z";
        }
        cout << "\n";
    }
}
