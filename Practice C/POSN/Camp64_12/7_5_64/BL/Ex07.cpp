#include<bits/stdc++.h>
using namespace std;

string str,str2;
int cnt[200];

main(){
    cout << "Input String1 ==> ";
    getline(cin, str);
    cout << "Length of String ==> " << str.size() << " Characters\n";
    str2 = str;
    reverse(str2.begin(), str2.end());
    cout << "Reverse String ==> " << str2 << "\n";
    cout << "Upper String ==> ";
    for(int i=0; str[i]!='\0'; i++){
        if(isalpha(str[i])){
            char tmp = toupper(str[i]);
            cnt[tmp]++;
            cout << tmp;
        }else{
            cout << str[i];
        }
    }
    cout << "\n=-=-=-=-=-=-=-=-=-=\nNumber of vowel\n=-=-=-=-=-=-=-=-=-=\n";
    cout << "A or a = " << cnt['A'] << "\n";
    cout << "E or e = " << cnt['E'] << "\n";
    cout << "I or i = " << cnt['I'] << "\n";
    cout << "O or o = " << cnt['O'] << "\n";
    cout << "U or u = " << cnt['U'] << "\n";
    cout << "=-=-=-=-=-=-=-=-=-=\n";
}
