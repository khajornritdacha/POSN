#include<bits/stdc++.h>
using namespace std;
int di;
string str;
main(){
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'Z'){
            di = 0;
            cout << "Z";
        }else if(str[i] == 'N'){
            if(di == 0){
                cout << "F";
            }else if(di == 1){
                cout << "RRRF";
            }else if(di == 2){
                cout << "RRF";
            }else if(di == 3){
                cout << "RF";
            }
            di = 0;
        }else if(str[i] == 'E'){
            if(di == 0){
                cout << "RF";
            }else if(di == 1){
                cout << "F";
            }else if(di == 2){
                cout << "RRRF";
            }else if(di == 3){
                cout << "RRF";
            }
            di = 1;
        }else if(str[i] == 'S'){
            if(di == 0){
                cout << "RRF";
            }else if(di == 1){
                cout << "RF";
            }else if(di == 2){
                cout << "F";
            }else if(di == 3){
                cout << "RRRF";
            }
            di = 2;
        }else if(str[i] == 'W'){
            if(di == 0){
                cout << "RRRF";
            }else if(di == 1){
                cout << "RRF";
            }else if(di == 2){
                cout << "RF";
            }else if(di == 3){
                cout << "F";
            }
            di = 3;
        }
    }
}
