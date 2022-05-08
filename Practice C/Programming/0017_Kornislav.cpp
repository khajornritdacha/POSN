#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int mx,a[5],n;
main(){
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a+4, greater<int>());
    cout << a[1]*a[3] << "\n";
}
