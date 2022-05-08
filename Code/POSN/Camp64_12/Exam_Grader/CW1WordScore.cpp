#include<bits/stdc++.h>
using namespace std;

int n,p[200];
string str;

main(){
    p['?'] = 0, p['A'] = p['E'] = p['I'] = p['L'] = p['N'] = p['O'] = p['R'] = p['S'] = p['T'] = p['U'] = 1;
    p['D'] = p['G'] = 2, p['B'] = p['C'] = p['M'] = p['P'] = 3, p['F'] = p['H'] = p['V'] = p['W'] = p['Y'] = 4;
    p['K'] = 5, p['J'] = p['X'] = 8, p['Q'] = p['Z'] = 10;
    cin >> n;
    while(n--){
        cin >> str;
        int ans = 0;
        for(int i=0; i<str.size(); i++){
            ans += p[toupper(str[i])];
        }
        cout << ans << "\n";
    }

}
