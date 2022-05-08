#include<bits/stdc++.h>
using namespace std;
char str[1000010];
int now,n;
main(){
    cin >> str+1;
    n = strlen(str+1);
    str[0] = '0';
    for(int i=n; i>=1; i--){
        now += str[i]-'0';
    }
    cout << now%3 << " ";
    now = 0;
    for(int i=n; i>=1; i-=2){
        now += (str[i]-'0')+(10*(str[i-1]-'0'));
    }
    cout << now%11 << "\n";
}
