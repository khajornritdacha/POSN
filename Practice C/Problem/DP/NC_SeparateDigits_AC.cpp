#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://atcoder.jp/contests/abc224/tasks/abc224_f

int n;
ll in[N],pw[N],sum2[N],dp1[N],dp2[N],qs[N],mod=998244353;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    cin >> str;
    n = str.size();
    pw[0] = sum2[0] = 1;
    for(int i = 1; i <= str.size(); i++){
        in[i] = str[i-1]-'0';
        pw[i] = (pw[i-1]*2)%mod;
        sum2[i] = (sum2[i-1]+pw[i])%mod;
    }
    /*cout << "IN: ";
    for(int i = 1; i <= n; i++){
        cout << in[i];
    }
    cout << "\n";*/
    ll now = 0;
    for(int i = 2; i <= n; i++){
        dp2[i] = (dp2[i-1]*10+in[i]*sum2[i-2])%mod;
    }
    for(int i = 1; i <= n; i++){
        now = (now*10)%mod;
        now = (now+in[i]);
        dp1[i] = (qs[i-1]+now+dp2[i])%mod;
        qs[i] = (qs[i-1]+dp1[i])%mod;
    }
    /*for(int i = 1; i <= n; i++){
        cout << dp1[i] << " " << dp2[i] << "\n";
    }*/
    cout << dp1[n]%mod;
    return 0;
}
