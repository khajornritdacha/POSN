#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
using ll = long long;

int n,mx;
char ans[N][105];

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int p,q,r; cin >> p >> q >> r;
        mx = max(mx, p);
        for(int j = q; j <= q+r-1; j++){
            ans[p][j] = 'x';
        }
    }

    for(int i = 1; i <= mx; i++){
        for(int j = 1; j <= 70; j++){
            if(ans[i][j] != 'x') ans[i][j] = 'o';
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}
