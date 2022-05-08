#include<bits/stdc++.h>
using namespace std;
using ll = long long;
com(int n, int r){
    ll tmp = 1;
    for(ll i=0; i<r; i++){
        tmp *= n-i;
        tmp /= i+1;
    }
    return tmp;
}
main(){
    int n,r;
    cin >> n >> r;
    cout << com(n,r);
}
