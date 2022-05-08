#include <bits/stdc++.h>
using namespace std;


int main(void){
    string str; cin >> str;
    int ans = 1, cnt = 1;
    for(int i = 1; i < str.size(); i++){
        if(str[i] == str[i-1]){
            cnt++;
        }else{
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}
