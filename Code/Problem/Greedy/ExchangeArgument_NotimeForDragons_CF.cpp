#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;

int n;
pair<int,int> a[N];
long long ans;

///https://codeforces.com/gym/101149/problem/B

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a+1, a+n+1, [&](const pi &A, const pi &B){
        return A.second-A.first < B.second-B.first;
    });

    long long now = 0;
    for(int i = 1; i <= n; i++){
        if(now < a[i].first){
            ans += a[i].first-now;
            now = a[i].first;
        }
        now -= a[i].second;
    }
    cout << ans << "\n";
    return 0;
}
