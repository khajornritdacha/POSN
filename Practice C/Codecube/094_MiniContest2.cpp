#include<bits/stdc++.h>
using namespace std;

int n;
bool ok = true;
string str;

main(){
    cin >> n >> str;
    for(int i=1; i<str.size(); i++){
        if(str[i] == str[i-1])
            ok = false;
    }
    if(ok)
        cout << "Accepted";
    else
        cout << "Wrong Answer";
}
