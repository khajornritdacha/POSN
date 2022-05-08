#include<bits/stdc++.h>
using namespace std;
int n,co[30][30];
main(){
    cin >> n;
    for(int i=0; i<=n; i++){
        co[i][0] = 1;
        for(int j=1; j<=i; j++){
            co[i][j] = co[i-1][j]+co[i-1][j-1];
        }
    }
    if(n%2)
        cout << co[n][n/2]*2;
    else
        cout << co[n][n/2];
}
