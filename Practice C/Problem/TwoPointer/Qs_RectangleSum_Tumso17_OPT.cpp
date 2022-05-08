#include <bits/stdc++.h>
using namespace std;

const int N = 305; ///Can't set N = 310
using ll = long long;

int R,C,K,a[N][N];
ll qs[N][N];

ll sum(int br, int bc, int sr, int sc){
    return qs[br][bc]-qs[br][sc-1]-qs[sr-1][bc]+qs[sr-1][sc-1];
}

int main(void){
    scanf("%d %d %d", &R, &C, &K);
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            scanf("%d", &a[i][j]);
            qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
        }
    }

    ll ans = 0; ///Can't Declare Global
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            int r = i-1;
            ll now = 0;
            for(int k = i; k >= 1; k--){
                now += a[k][j];
                if(now > K) break;
                r = k;
            }
            now = 0;
            for(int k = j; k >= 1; k--){
                now += sum(i, k, r, k);
                while(now > K){
                    now -= sum(r, j, r, k);
                    r++;
                }
                ans += i-r+1;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
