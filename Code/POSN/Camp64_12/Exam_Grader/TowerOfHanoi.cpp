#include<bits/stdc++.h>
using namespace std;

string str[3];
int n;

void solve(int lv, int st, int ed, int au){
    if(lv == 0)
        return;
    solve(lv-1, st, au, ed);
    cout << str[st] << " => " << str[ed] << "\n";
    solve(lv-1, au, ed, st);
}

main(){
    cin >> n >> str[0] >> str[1] >> str[2];
    solve(n, 0, 2, 1);
}
