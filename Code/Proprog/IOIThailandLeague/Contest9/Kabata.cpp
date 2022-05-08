#include<bits/stdc++.h>
using namespace std;


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        bool ok = true;
        int n = str.size();
        for(int i=0; i<n; i++){
            if(i+4 < n and str[i] == 'b' and str[i+1] == 'a' and str[i+2] == 'k' and str[i+3] == 'k' and str[i+4] == 'a'){
                i+=4;
                continue;
            }
            if(i+1 < n and str.substr(i, 2) == "ta"){
                i++;
                continue;
            }
            if(i+1 < n and str.substr(i, 2) == "ka"){
                i++;
                continue;
            }
            if(i+1 < n and str.substr(i, 2) == "ba"){
                if(i+3 < n and str.substr(i+2, 2) == "ka"){
                    ok = false;
                    break;
                }
                i++;
                continue;
            }
            ok = false;
            break;
        }
        if(ok)
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }
}
