#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
int n,a[N];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int lc = a[1]/__gcd(a[1], a[2])*a[2];
    for(int i=2; i<=n; i++){
        lc = a[i]/__gcd(a[i], lc)*lc;
    }
    cout << lc << "\n";
}
