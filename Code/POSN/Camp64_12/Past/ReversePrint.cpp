#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    if(n == 0)
        return;
    solve();
    cout << n << " ";
}
main(){
    solve();
}
