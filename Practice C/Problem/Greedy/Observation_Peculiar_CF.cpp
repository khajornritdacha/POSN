//https://codeforces.com/problemset/problem/1628/B
#include <bits/stdc++.h>
using namespace std;

bool ispar(string s){
    if(s.size() == 1) return 1;
    if(s.size() == 2) return s[0] == s[1];
    if(s.size() == 3) return s[0] == s[2];
    return 0;
}

void test_case(){
    int n; cin >> n;

    bool ok = false;
    set<string> scut, ss;

    for(int i = 1; i <= n; i++){
        string str; cin >> str;

        if(ok or ispar(str)){
            ok = true;
            continue;
        }

        if(str.size() == 3){
            scut.insert(str.substr(0, 2));
        } 

        reverse(str.begin(), str.end());

        if(ss.find(str) != ss.end() or (str.size() == 3 and ss.find(str.substr(0, 2)) != ss.end()))    
            ok = true;
        
        else if(str.size() == 2 and scut.find(str) != scut.end())
            ok = true;

        reverse(str.begin(), str.end());
        ss.insert(str);
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) test_case();

    return 0;
}