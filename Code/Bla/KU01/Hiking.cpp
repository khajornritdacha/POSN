#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

using ll = long long;
const int N = 35;

int n,S;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> S;
    int mx = S, mn = S;
    for(int i = 1, A; i <= n; i++){
        cin >> A;
        int tmn = 1e9, tmx = 0;
        if(A%3 == 0){
            tmn = min(tmn, A/3*2*5);
            tmx = max(tmx, A/3*2*5);
        }
        if(A%4 == 0){
            tmn = min(tmn, A/4*2*5);
            tmx = max(tmx, A/4*2*5);
        }
        mx -= tmn;
        mn -= tmx;
    }
    cout << mn << " " << mx << "\n";
    return 0;
}
