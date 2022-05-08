#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n,a[N];

///https://atcoder.jp/contests/abc102/tasks/arc100_a

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] -= i;
    }
    sort(a+1, a+n+1);
    int med = (n+1)/2;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans += abs(a[i]-a[med]);
    }
    cout << ans << "\n";
    return 0;
}
