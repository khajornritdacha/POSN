#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const int base = 101;
const int N = 100010;
ll pw[N],inv_pw[N],hsh[N],hsp[N];
string text,pat;

ll add(ll x, ll y){
    return ((x+y)%mod + mod)%mod;
}
ll mul(ll x, ll y){
    return (((x*y)%mod) + mod)%mod;
}
ll inv(ll x, ll y){
    return 1 < x ? y-inv(y%x,x)*y/x : 1;
}
ll get_hsh(int l, int r){
    return mul(add(hsh[r],-hsh[l-1]), inv_pw[l]);
}
ll get_pat(int l, int r){
    return mul(add(hsp[r], -hsp[l-1]), inv_pw[l]);
}
main(){
    hsh[0] = 0, pw[0] = 1;
    cin >> text >> pat;
    for(int i=1; i<=text.size(); i++){
        pw[i] = mul(pw[i-1], base);
        hsh[i] = add(hsh[i-1], mul(pw[i], text[i-1]));
    }

    for(int i=1; i<=pat.size(); i++){
        hsp[i] = add(hsp[i-1], mul(pw[i], pat[i-1]));
    }

    for(int i=0; i<=text.size(); i++){
        cout << pw[i] << " \n"[i==text.size()];
    }

    for(int i=0; i<=text.size(); i++){
        inv_pw[i] = inv(pw[i], mod);
        cout << inv_pw[i] << " \n"[i==text.size()];
    }

    for(int i=1; i<=text.size(); i++){
        cout << "I: " << i << "-> " << get_hsh(1,i) << "\n";
    }

    for(int i=1; i<=pat.size(); i++){
        cout << "I: " << i << "-> " << get_pat(1,i) << "\n";
    }

    for(int i=pat.size(); i<=text.size(); i++){
        if(get_pat(1,pat.size()) == get_hsh(i-pat.size()+1,i)){
            cout << "FOUND at : " << i << "\n";
            //cnt++;
        }
    }
}
