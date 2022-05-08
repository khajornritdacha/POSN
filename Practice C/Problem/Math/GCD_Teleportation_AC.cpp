#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;
using pi = pair<int,int>;

int n,X[N],Y[N];

///https://atcoder.jp/contests/abc226/tasks/abc226_d

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> X[i] >> Y[i];
    }

    map< pair<int,int>, int> mp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;

            int dx = X[i]-X[j], dy = Y[i]-Y[j];
            int g = abs(__gcd(dx, dy));
            dx /= g, dy /= g;
            mp[pi(dx, dy)]++;
        }
    }

    /*for(auto [pos, cnt] : mp){
        cout << pos.first << " " << pos.second << "\n";
    }*/

    cout << mp.size() << "\n";
    return 0;
}
