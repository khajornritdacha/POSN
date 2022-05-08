#include<bits/stdc++.h>
#define DEBUG true
using namespace std;

const int N = 2010;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

string a,b;
map<ll, ll> dp[20][2][2][2],bt[20][2][2][2];
///https://codeforces.com/gym/100886/problem/G

ll solve(int idx=0, bool les=0, bool mor=0, bool lead=0, ll mul=1){
    if(idx == b.size()){
        return mul;
    }
    if(dp[idx][les][lead][mor].count(mul)) return dp[idx][les][mor][lead][mul];

    ll mx = 0;
    int lo = (mor ? 0 : a[idx]-'0'), hi = (les ? 9 : b[idx]-'0');
    for(int j=lo; j<=hi; j++){
        bool go = lead|(j != 0);
        ll res = solve(idx+1, les|(j != hi), mor|(j != lo), go, (go ? mul*j : 1));
        if(res >= mx){
            mx = res;
            bt[idx][les][mor][lead][mul] = j;
        }
    }

    return dp[idx][les][mor][lead][mul] = mx;
}

void test_case(){
    cin >> a >> b;
    while(a.size() < b.size())
        a.insert(a.begin(), '0');
    //cout << a << " " << b << "\n";

    solve();

    //cout << "CHK " << bt[1][1][0][0][1] << "\n";
    int pos = 0, mor = 0, les = 0, lead = 0;
    ll mul = 1, ans = 0;
    while(pos < b.size()){
        ans *= 10;
        /*cout << "NOW : " << bt[pos][les][mor][lead][mul] << "\n";
        cout << "POS : " << pos << "\n";
        cout << "Les : " << les << "\n";
        cout << "Mor : " << mor << "\n";
        cout << "Lead : " << lead << "\n";
        cout << "Mul : " << mul << "\n\n";*/


        int now = bt[pos][les][mor][lead][mul];
        ans += now;
        lead |= (now != 0);
        mul *= (lead ? now : 1);
        les |= (now != b[pos]-'0');
        mor |= (now != a[pos]-'0');
        pos++;
    }
    cout << ans << "\n";

}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
}
