#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int wa,br,eg,res;
main(){
    cin >> wa >> br >> eg;
    res = min({wa/3, br/4, eg/2});
    cout << res << " " << wa-res*3 << " " << br-res*4 << " " << eg-res*2;
}
