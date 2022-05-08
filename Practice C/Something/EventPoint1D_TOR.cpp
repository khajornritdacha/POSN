#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

int n,a[N],ep[N],_plus[N],result[N],num_point;

int main(void){
    cin >> n; ///Total of n blocks
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> num_point;
    for(int i = 1; i <= num_point; i++){
        int l,r,val;
        cin >> l >> r >> val;
        ep[l] += val;
        ep[r+1] -= val;
    }
    for(int i = 1; i <= n; i++){
        _plus[i] = ep[i]+_plus[i-1];
    }
    for(int i = 1; i <= n; i++){
        result[i] = _plus[i]+a[i];
        cout << result[i] << " \n"[i==n];
    }
    return 0;
}

/*
8
0 -1 10 5 -3 7 6 -2
3
2 6 10
1 8 -3
4 4 4
*/
