#include<bits/stdc++.h>
using namespace std;
main(){
    while(true){
        int a,b,s;
        cin >> a >> b >> s;
        if(a == 0 and b == 0 and s == 0){
            break;
        }
        if(a+b == s){
            cout << "+";
        }else if(a-b == s){
            cout << "-";
        }else if(a*b == s){
            cout << "*";
        }else if(a/b == s){
            cout << "/";
        }else if(a%b == s){
            cout << "%";
        }
        cout << "\n";
    }
}
