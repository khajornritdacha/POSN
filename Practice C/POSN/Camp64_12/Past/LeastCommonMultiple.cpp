#include<bits/stdc++.h>
using namespace std;
int a,b,c;
main(){
    cin >> a >> b >> c;
    int l1 = a/__gcd(a,b)*b;
    cout << l1/__gcd(l1,c)*c;
}
