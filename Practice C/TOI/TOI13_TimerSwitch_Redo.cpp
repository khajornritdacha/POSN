#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
string str;
ll want, cur, pw, base = 31, mod = 1e9+7;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> str;
    for(int i = 0; i < n; i++){
        want *= base;
        want += str[i]-'0';
    }
    cur = want;

    pw = 1;
    for(int i = 0; i < n-1; i++) pw = pw*base;

    //cout << "WANT : " << cur << " " << want << "\n";

    int ans = -1;
    for(int i = 0; i < n; i++){
        cur -= pw*(str[i]-'0');
        cur *= base;
        cur += str[i]-'0';
        //cout << cur << " " << want << "\n";
        if(cur == want){
            ans = i+1;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
