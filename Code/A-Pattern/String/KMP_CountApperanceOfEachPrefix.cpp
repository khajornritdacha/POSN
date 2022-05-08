#include<bits/stdc++.h>
using namespace std;
string str;
int n,pie[1010],ans[1010];

main(){
    cin >> str;
    n = str.size();
    for(int i=1, idx=0; i < n; i++){
        while(idx>0 && str[idx]!=str[i])
            idx = pie[idx-1];
        if(str[idx] == str[i])
            idx++;
        pie[i] = idx;
        ans[pie[i]]++;
    }

    ///print check
    cout << "Pie : ";
    for(int i=0; i<n; i++){
        cout << pie[i] << " \n"[i==n-1];
    }
    cout << "Ans : ";
    for(int i=0; i<=n; i++){
        cout << ans[i] << " \n"[i==n];
    }

    ///add counts of longer substr to its shorter substr
    for(int i=n; i>=1; i--){
        ans[pie[i-1]]+=ans[i];
    }

    ///plus 1 for the original one from string str
    for(int i=1; i<=n; i++){
        cout << "Found \"" << str.substr(0,i) << "\" " << ans[i]+1 << " time(s)\n";
    }
}

/*
atcacatcatca
*/
