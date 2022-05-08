#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n,m,ans[5];
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string str;
        char lv;
        cin >> str >> lv;
        mp[str] = lv-'a';
    }
    for(int i=1; i<=m; i++){
        string str;
        bool ok = true;
        cin >> str;
        ans[mp[str]]++;
    }
    for(int i=0; i<3; i++){
        if(ans[i] < 4)
            cout << 0;
        else if(ans[i] == 4)
            cout << 1;
        else
            cout << 2;
        cout << "\n";
    }
}
