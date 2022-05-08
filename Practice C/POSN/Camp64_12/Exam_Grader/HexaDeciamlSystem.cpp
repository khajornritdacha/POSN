#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e3+100;
string str;
int want;

main(){
    cin >> str >> want;
    int n = str.size();
    if(isalpha(str[n-want-1])){
        cout << str[n-want-1]-'A'+10;
    }else{
        cout << str[n-want-1];
    }
    cout << "x16^" << want << "\n";
}
