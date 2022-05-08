#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

///https://atcoder.jp/contests/abc224/tasks/abc224_e

struct DATA{
    int r,c,a,idx;
};

int R,C,n,dp[N];
DATA a[N];
map<int, int> mxr, mxc;

int main(void){
    scanf("%d %d %d", &R, &C, &n);
    for(int i = 1; i <= n; i++){
        int r,c,val; cin >> r >> c >> val;
        a[i] = {r, c, val, i};
    }

    sort(a+1, a+n+1, [&](const DATA &A, const DATA &B){
        return A.a > B.a;
    });

    for(int i = 1, j = 0; i <= n; i++){
        dp[a[i].idx] = max(mxr[a[i].r], mxc[a[i].c])+1;
        if(i+1 <= n and a[i].a != a[i+1].a){
            while(j < i){
                j++;
                mxr[a[j].r] = max(mxr[a[j].r], dp[a[j].idx]);
                mxc[a[j].c] = max(mxc[a[j].c], dp[a[j].idx]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%d\n", dp[i]-1);
    }
    return 0;
}
