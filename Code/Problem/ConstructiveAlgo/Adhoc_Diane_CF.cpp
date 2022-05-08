//https://codeforces.com/problemset/problem/1554/D

#include <bits/stdc++.h>
using namespace std;

void test_case(){
    int n; cin >> n;
    string res = "";

    if(n&1){
        res.push_back('c');
        n--;
    }
    
    n /= 2;
    for(int i = 1; i <= n; i++) res.push_back('a');
    
    if(n > 0){
        res.push_back('b');
        n--;
    }

    for(int i = 1; i <= n; i++) res.push_back('a');
    

    cout << res << "\n";

    return;
}

int main(void){
    int t; cin >> t;
    while(t--) test_case();
}