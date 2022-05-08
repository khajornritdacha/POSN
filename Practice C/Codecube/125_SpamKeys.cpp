#include<bits/stdc++.h>
using namespace std;

int n,cnt;
string str;

main(){
    cin >> n >> str;
    for(int i=0; i<str.size(); i++){
        //cout << "I : " << i << " -> " << str.substr(i, 8) << ", " << str.substr(i, 5) << "\n";
        if(i+7 < str.size() and str.substr(i, 8) == "SPACEBAR"){
            cnt++;
            i+=7;
            continue;
        }

        if(i+4 < str.size() and str.substr(i, 5) == "SHIFT"){
            cnt++;
            i+=4;
            continue;
        }

        if(str[i] == 'Q' or str[i] == 'W' or str[i] == 'E' or str[i] == 'A' or str[i] == 'S' or str[i] == 'D' or str[i] == 'V'){
            cnt++;
        }
    }
    cout << cnt;
}
