#include<bits/stdc++.h>
using namespace std;
string t,Pa;
int n,m,pie[1010],chk[1010];
main(){
    ///Input text then pattern
    cin >> t >> Pa;
    n = t.size(), m=Pa.size();

    ///pre-process (i start at 1 / idx start at 0)
    for(int i=1, idx=0; i<m; i++){
        while(idx > 0 && Pa[i]!=Pa[idx])
            idx = pie[idx-1];
        if(Pa[i] == Pa[idx])
            idx++;
        pie[i] = idx;
        //cout << pi[i] << " \n"[i==m-1];
    }

    ///pattern matching
    for(int i=0, idx=0; i<n; i++){
        while(idx > 0 && t[i] != Pa[idx])
            idx = pie[idx-1];
        //cout << i << " " << idx << " " << t[i] << " " << p[idx] << "\n";
        if(t[i] == Pa[idx])
            idx++;
        chk[i] = idx;
        if(idx == m){
            cout << "Pattern Found: " << i << "\n";
            idx = pie[idx-1];
        }
    }

    ///Idx in each position
    for(int i=0; i<n; i++){
        cout << chk[i] << " \n"[i==n-1];
    }
}

/*
atcacatcatca
atca
*/
