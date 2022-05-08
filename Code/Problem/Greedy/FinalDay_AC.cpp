#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, K, a[N], order[N];

///https://atcoder.jp/contests/abc228/tasks/abc228_c

int main(void){
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            int x; cin >> x;
            a[i] += x;
        }
        order[i] = a[i];
    }

    sort(order+1, order+n+1, greater<int>());

    for(int i = 1; i <= n; i++){
        if(a[i] + 300 >= order[K]){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}