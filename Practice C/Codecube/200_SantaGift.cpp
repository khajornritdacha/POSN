#include<bits/stdc++.h>
using namespace std;

string str1,str2;

main(){
    cin >> str1 >> str2;
    if(str1 != str2){
        cout << max(str1.size(), str2.size());
    }else{
        cout << "-1";
    }
}
