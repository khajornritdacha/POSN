#include<bits/stdc++.h>
using namespace std;
int a,b,c;
main(){
    cin >> a >> b >> c;
    if(a+b == c){
        cout << "+";
    }else if(a-b == c){
        cout << "-";
    }else if(a*b == c){
        cout << "*";
    }else if(a/b == c){
        cout << "/";
    }else if(a%b == c){
        cout << "%";
    }
}
