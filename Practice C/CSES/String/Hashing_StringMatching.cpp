#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

ll pw[N],hsh[N],base = 31, mod = 1e9+7;

ll gh(int r, int l){
    if(l > r) return 0;
    if(l <= 0) return hsh[r];
    return (hsh[r] - (pw[r-l+1]*hsh[l-1])%mod + mod)%mod;

}

int main(void){
    string A,P;
    cin >> A >> P;
    pw[0] = 1;
    ll want = 0;
    for(int i = 0; i < P.size(); i++){
        want = ((want*base)+(P[i]-'a'+1))%mod;
        pw[i+1] = (pw[i]*base)%mod;
    }

    //cout << want << "\n";

    int dif = (int)A.size()-(int)P.size()+1, ans = 0;
    for(int i = 0; i < A.size(); i++){
        hsh[i+1] = ((hsh[i]*base) + (A[i]-'a'+1))%mod;
        if(i+1 >= P.size() and gh(i+1, i-P.size()+2) == want){
            ans++;
        }
    }
    cout << ans << "\n";

    //cout << gh(5, 4) << "\n";
    return 0;
}
