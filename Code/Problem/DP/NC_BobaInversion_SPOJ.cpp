#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,a[N],ans[N][N],pre[N][N];

///https://www.spoj.com/problems/BOBAINV/

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int cur = 1; cur <= n; cur++){
        for(int j = cur-1; j >= 0; j--){
            pre[j][cur] = pre[j+1][cur]+(a[j] > a[cur]);
        }
    }

    for(int l = 1; l <= n; l++){
        for(int r = l; r <= n; r++){
            ans[l][r] = ans[l][r-1]+pre[l][r];
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int l,r; cin >> l >> r;
        cout << ans[l][r] << "\n";
    }
    return 0;
}
