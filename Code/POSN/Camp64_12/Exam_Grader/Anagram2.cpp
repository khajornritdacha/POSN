#include<bits/stdc++.h>
using namespace std;

string str,str2;
int cnt[30],cnt2[30],cou[30];

main(){
    cin >> str >> str2;
    for(int i=0; i<str.size(); i++){
        cnt[str[i]-'A']++;
    }
    for(int i=0; i<str2.size(); i++){
        cnt2[str2[i]-'A']++;
    }

    int res = 0;
    for(int i=0; i<8; i++){
        cou[i] = abs(cnt[i]-cnt2[i]);
        res += abs(cnt[i]-cnt2[i]);
    }

    for(int i=0; i<8; i++){
        cout << cnt[i] << " ";
    }
    cout << "\n";
    for(int i=0; i<8; i++){
        cout << cnt2[i] << " ";
    }
    cout << "\n";
    for(int i=0; i<8; i++){
        cout << cou[i] << " ";
    }
    cout << "\n";

    if(res <= 3){
        cout << "anagram";
    }else{
        cout << "no";
    }
}
