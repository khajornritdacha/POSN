#include<bits/stdc++.h>
using namespace std;
int n,m;
main(){
    int a = 3;
    int b = 1;
    int sum = 3;
    cin >> n >> m;
    for(; a!=n or b!=m; ){
        int ta = a+b;
        int tb = a-b;
        a = ta;
        b = tb;
        sum+=a*b;
    }
    cout << sum;
}
