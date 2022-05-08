#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int a,b,c,d,res;
main(){
    cin >> a >> b >> c >> d;
    for(int i=1; i<=8; i++){
        int x;
        cin >> x;
        if(x >= a){
            cout << 4;
            res+=4;
        }else if(x >= b){
            cout << 3;
            res+=3;
        }else if(x >= c){
            cout << 2;
            res+=2;
        }else if(x >= d){
            cout << 1;
            res+=1;
        }else{
            cout << 0;
        }
        cout << "\n";
    }
    cout << setprecision(6) << fixed << (float)res/8;
}
