#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1603/B

void test_case(){
    long long x, y; cin >> x >> y;
    if(x > y) cout << x+y << "\n";
    else cout << y-(y%x)/2 << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}