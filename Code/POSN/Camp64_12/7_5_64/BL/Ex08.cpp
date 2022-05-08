#include<bits/stdc++.h>
using namespace std;

string str1,str2;
int cnt[200],cnt2[200];
bool ok = true;

main(){
    getline(cin, str1);
    getline(cin, str2);
    for(int i=0; str1[i]!='\0'; i++){
        if(str1[i] >= 'a' and str1[i] <= 'z')
            cnt[str1[i]+'A'-'a']++;
        else
            cnt[str1[i]]++;
    }
    for(int i=0; str2[i]!='\0'; i++){
        if(str2[i] >= 'a' and str2[i] <= 'z')
            cnt2[str2[i]+'A'-'a']++;
        else
            cnt2[str2[i]]++;
    }
    for(int i='A'; i<='Z'; i++){
        if(cnt[i] != cnt2[i])
            ok = false;
    }
    if(!ok)
        cout << "Not ";
    cout << "Anagram";
    //cout << str1 << "\n" << str2;
}
