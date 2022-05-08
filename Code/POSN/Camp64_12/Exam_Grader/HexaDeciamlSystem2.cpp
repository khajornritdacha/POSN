#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e3+100;
string str;
int want;

main(){
    cin >> str;
    int n = str.size();
    for(int i=0; i<str.size(); i++){
        if(i!=0)
            cout << "+";
        if(isalpha(str[i])){
            cout << str[i]-'A'+10;
        }else{
            cout << str[i];
        }
        cout << "x16^" << n-i-1;

    }
}
