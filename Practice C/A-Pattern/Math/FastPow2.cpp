#include<bits/stdc++.h>
using namespace std;
int expo(int b, int p){
    if(p==0)
        return 1;
    if(p==1)
        return b;
    int tmp = expo(b, p/2)%mod;
    tmp*=tmp%mod;
    if(p%2 == 1){
        tmp*=b%mod;
    }
    return tmp%mod;
}
main(){
    int b,p;
    cin >> b >> p;
    cout << (expo(b, p)%mod+mod)%mod;
}
