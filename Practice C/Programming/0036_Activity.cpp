#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
const int N = 1e2+10;
long long n,pas[30][30];
main(){
    for(int i=0; i<=25; i++){
        pas[i][0] = 1;
        for(int j=1; j<=i; j++){
            pas[i][j] = pas[i-1][j]+pas[i-1][j-1];
        }
    }
    cin >> n;
    if(n%2)
        cout << pas[n][n/2]*2;
    else
        cout << pas[n][n/2];
}
