#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e6+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n;

///https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=5014

struct DATA{
    ll O,N;
};

DATA a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> a[i].O >> a[i].N;
        }

        sort(a+1, a+n+1, [&](const DATA &A, const DATA &B){
            if(A.N >= A.O and B.N < B.O) return true;
            if(A.N < A.O and B.N >= B.O) return false;
            if(A.N >= A.O and B.N >= B.O) return A.O < B.O;
            return A.N > B.N; ///A.N < A.O and B.N < B.O
        });

        if(DEBUG){
            for(int i = 1; i <= n; i++){
                cout << a[i].O << " " << a[i].N << "\n";
            }
        }

        ll usable = 0, ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i].O > usable){
                ans += a[i].O-usable;
                usable = 0;
            }else{
                usable -= a[i].O;
            }
            usable += a[i].N;
        }
        cout << ans << "\n";
    }
    return 0;
}
