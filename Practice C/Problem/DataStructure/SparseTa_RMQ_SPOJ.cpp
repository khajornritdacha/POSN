#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, K = 25;

int n,Q,a[N],ta[N][K],blog[N];

///https://www.spoj.com/problems/RMQSQ/

int ask(int l, int r){
    int lg = blog[r-l+1];
    return min(ta[l][lg], ta[r-(1<<lg)+1][lg]);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ta[i][0] = a[i];
    }

    for(int i = 2; i <= n; i++){
        blog[i] = blog[i/2]+1;
    }

    for(int k = 1; k <= K; k++){
        for(int i = 1; i+(1<<k)-1 <= n; i++){
            ta[i][k] = min(ta[i][k-1], ta[i+(1<<(k-1))][k-1]);
        }
    }

    cin >> Q;

    while(Q--){
        int l,r; cin >> l >> r;
        l++, r++;
        cout << ask(l, r) << "\n";
    }
    return 0;
}
