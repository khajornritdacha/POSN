#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://codeforces.com/problemset/problem/808/D

int n;
ll sum,want;

bool solve(const vector<ll> &a){
    vector<ll> qs(n, 0);
    multiset<int> ms;
    for(int i = 0; i < n; i++){
        if(i > 0) qs[i] += qs[i-1];
        qs[i] += a[i];
        if(qs[i] == want){return true;}
        ms.insert(a[i]);
    }
    if(ms.count(want)) return true;
    for(int i = 0; i < n; i++){
        ms.erase(ms.find(a[i]));
        if(want-qs[i] <= 0) return false;
        if(ms.count(want-qs[i]) > 0)
            return true;
    }
    return false;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%2 != 0){
        cout << "NO\n";
        return 0;
    }
    want = sum/2;

    bool ok = false;
    ok |= solve(a);
    reverse(a.begin(), a.end());
    ok |= solve(a);

    if(ok){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
