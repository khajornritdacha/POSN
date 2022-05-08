#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;

///https://codeforces.com/problemset/problem/1119/D
///answer = total - duplicate
///total = n*(r-l+1)
///duplicate = (r-l+1)*k - qs(k) when k is the largest difference between 2 frets that less than or equal to r-l+1 and qs is sum of diffecences

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> vec(n);
    for(ll &x : vec) cin >> x;
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end())-vec.begin());

    vector<ll> dif = {0}, qs(vec.size());
    for(int i = 1; i < vec.size(); i++){
        dif.emplace_back(vec[i]-vec[i-1]);
    }
    sort(dif.begin(), dif.end());


    for(int i = 1; i < dif.size(); i++){
        qs[i] = qs[i-1] + dif[i];
    }

    int Q; cin >> Q;
    while(Q--){
        ll l, r; cin >> l >> r;
        int k = upper_bound(dif.begin(), dif.end(), r-l+1)-dif.begin()-1;
        int n = dif.size();
        //cout << "K & n : " << k << " " << n << " " << qs[k] << "\n";
        cout << (r-l+1)*(n-k)+qs[k] << " ";
    }
    return 0;
}
