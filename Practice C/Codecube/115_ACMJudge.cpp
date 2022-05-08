#include<bits/stdc++.h>
using namespace std;


void solve(){
        bool re,te,wa;
        re = te = wa = false;
        string str;
        cin >> str;
        for(int i=0; i<str.size(); i++){
            if(str[i] == 'X'){
                re = true;
            }
            if(str[i] == 'T'){
                te = true;
            }
            if(str[i] == '-'){
                wa = true;
            }
        }
        if(re)
            cout << "No - Runtime error";
        else if(te)
            cout << "No - Time limit exceeded";
        else if(wa)
            cout << "No - Wrong answer";
        else
            cout << "Yes";
        return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for(int i=1; i<=T; i++){
        cout << "Case #"<<i<<": ";
        solve();
        cout << "\n";
    }
}
