#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
///https://codeforces.com/problemset/problem/1526/B
void test_case(){
    cin >> n;
    bool ok = false;
    for(int i=0; i<12; i++){
        if(n%11 == 0){
            ok = true;
            break;
        }
        n-=111;
        if(n < 0) break;
    }

    if(ok)
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
