#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 3e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://codeforces.com/problemset/problem/1598/D

void test_case(){
    int n;
    cin >> n;

    vector<int> to(n+5), dif(n+5);
    map<int,int> cntt, cntd;

    for(int i = 1; i <= n; i++){
        cin >> to[i] >> dif[i];
        cntt[to[i]]++;
        cntd[dif[i]]++;
    }

    ll ans = n*(n-1)*(n-2)/6;
    for(int i = 1; i <= n; i++){
        ans -= (cntt[to[i]]-1)*(cntd[dif[i]]-1); ///current as middle
    }
    cout << ans << "\n";
}


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
