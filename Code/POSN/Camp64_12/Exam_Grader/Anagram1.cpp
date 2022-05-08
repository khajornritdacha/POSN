#include<bits/stdc++.h>
using namespace std;

string str;
int cnt[30];

main(){
    cin >> str;
    for(int i=0; i<str.size(); i++){
        cnt[str[i]-'A']++;
    }
    for(int i=0; i<8; i++){
        cout << cnt[i] << " ";
    }
}
