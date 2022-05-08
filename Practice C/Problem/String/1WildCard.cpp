#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const ll base = 101;
const int N = 100010;
string pat,text;
ll pw[N],hsh_p[N],hsh_t[N],inv_pw[N];
int n,m;
ll add(ll x, ll y){
    return ((x+y)%mod + mod)%mod;
}
ll mul(ll x, ll y){
    return ((x*y)%mod + mod)%mod;
}
ll inv(ll x, ll y){
    return 1 < x ? y-inv(y%x,x)*y/x : 1;
}
ll get_hsh_t(int l, int r){
    return mul(add(hsh_t[r], -hsh_t[l-1]), inv_pw[l]);
}
ll get_hsh_p(int l, int r){
    return mul(add(hsh_p[r], -hsh_p[l-1]), inv_pw[l]);
}
int bs(int st){
    int l=0,r=m,mid,ans=0;
    while(l<=r){
        mid = (l+r)/2;
        if(get_hsh_t(st,st+mid-1) == get_hsh_p(1,mid)){
            l = mid+1;
            ans = max(ans,mid);
        }else{
            r = mid-1;
        }
    }
    return ans;
}
int bsr(int ed){
    int l=0,r=m,mid,ans=0;
    while(l<=r){
        mid = (l+r)/2;
        if(get_hsh_t(ed-mid+1,ed) == get_hsh_p(m-mid+1,m)){
            l = mid+1;
            ans = max(ans,mid);
        }else{
            r = mid-1;
        }
    }
    return ans;
}
main(){
        cin >> text >> pat;
        pw[0]=1;
        n = text.size();
        m = pat.size();
        for(int i=1; i<=text.size(); i++){
            pw[i] = mul(pw[i-1], base);
            hsh_t[i] = add(hsh_t[i-1], mul(text[i-1],pw[i]));
        }
        for(int i=0; i<=text.size(); i++){
            inv_pw[i] = inv(pw[i], mod);
        }
        for(int i=1; i<=pat.size(); i++){
            hsh_p[i] = add(hsh_p[i-1], mul(pat[i-1],pw[i]));
        }
        for(int i=m; i<=n; i++){
            int k1 = bs(i-pat.size()+1);
            int k2 = bsr(i);
            cout << "I: " << i << " " << k1 << " " << k2 << "\n";
            if(k1+k2 >= m){
                cout << "OK at : " << i-m+1 << "\n";
            }else if(k1+k2 == m-1){
                cout << "Use card at : " << i-m+1 << "\n";
            }
        }
}
