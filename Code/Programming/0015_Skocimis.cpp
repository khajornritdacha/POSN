#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(b-a,c-b)-1;
}
