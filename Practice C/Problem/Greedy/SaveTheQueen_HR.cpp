#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+10;
using db = double;

int K, n, a[N];
db eps = 1e-6;

//https://www.hackerrank.com/contests/hourrank-31/challenges/save-the-queen/problem

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater<int>());

    db sum = 0, ans = 0;
    for(int i = K+1; i <= n; i++) sum += a[i];

    for(int i = K, j = 1; i >= 1; i--, j++){
        sum += a[i];
        db tmp = sum/j;
        ans = tmp;
        if(tmp < a[i-1]) break;
    }

    cout << setprecision(10) << fixed << ans << "\n";

    return 0;
}