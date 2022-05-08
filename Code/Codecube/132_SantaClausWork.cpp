#include<bits/stdc++.h>
using namespace std;

int n;
long long pw[35];

main(){
    pw[0] = 1;
    cin >> n;
    for(int i=1; i<=n; i++){
        pw[i] = pw[i-1]*4;
    }
    cout << pw[n];
}
