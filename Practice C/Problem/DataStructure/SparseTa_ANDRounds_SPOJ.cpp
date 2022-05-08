#include <bits/stdc++.h>
using namespace std;

const int LOG = 25;

///https://www.spoj.com/problems/ANDROUND/

void test_case(){
    int n,K, AND = (1<<31)-1; cin >> n >> K;
    int ta[3*n+5][LOG+1] = {};

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ta[i][0] = ta[n+i][0] = ta[n+n+i][0] = x;
        AND &= x;
    }

    if(K > n/2){
        for(int i = 1; i <= n; i++)
            cout << AND << " ";
        cout << "\n";
        return;
    }

    for(int k = 1; k <= LOG; k++){
        for(int i = 1; i+(1<<k)-1 <= 3*n; i++){
            ta[i][k] = ta[i][k-1]&ta[i+(1<<(k-1))][k-1];
        }
    }

    for(int i = 1; i <= n; i++){
        int l = i+n-K, r = i+n+K;
        int res = (1<<31)-1;
        for(int k = LOG; k >= 0; k--){
            if(1<<k <= r-l+1){
                res &= ta[l][k];
                l += 1<<k;
            }
        }
        cout << res << " ";
    }
    cout << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
