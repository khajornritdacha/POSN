#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, K = 25;

int a[N],n,Q,ta[N][K],blog[N];
///https://cses.fi/problemset/task/1647

int ask(int l, int r){
    int len = r-l+1;
    int lg = blog[len];
    //cout << "LG : " << lg << "\n";
    return min(ta[l][lg], ta[r-(1<<lg)+1][lg]);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ta[i][0] = a[i];
        if(i >= 2)
            blog[i] = blog[i/2]+1;
    }

    for(int k = 1; k <= K; k++){
        for(int i = 1; i+(1<<k)-1 <= n; i++){
            ta[i][k] = min(ta[i][k-1], ta[i+(1<<(k-1))][k-1]);
        }
    }

    while(Q--){
        int l, r;
        cin >> l >> r;
        cout << ask(l, r) << "\n";
    }
    return 0;
}
