#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1621/D

void test_case(){
    int n; cin >> n;
    int C[2*n+5][2*n+5] = {};
    long long ans = 0;
    for(int i = 1; i <= 2*n; i++){
        for(int j = 1; j <= 2*n; j++){
            cin >> C[i][j];
            if(i > n and j > n) ans += C[i][j];
        }
    }

    ans += min({C[n][n+1], C[n+1][n], C[n][2*n], C[2*n][n], C[1][n+1], C[1][2*n], C[n+1][1], C[2*n][1]});
    // cout << C[n][n+1] <<  C[n+1][n] <<  C[n][2*n] <<  C[2*n][n] << "\n";
    cout << ans << "\n";
    
    return;
}

int main(void){
    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}