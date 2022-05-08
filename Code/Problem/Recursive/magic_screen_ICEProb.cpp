//https://codeforces.com/contestInvitation/289dc0bc3f5042a41b0d7d36e9827ebca71666f8
#include <bits/stdc++.h>
using namespace std;

const int N = 150;

int arr[N][N];

int solve(int lr, int lc, int br, int bc){
    if(lr == br and lc == bc) return arr[lr][lc];
    int cnt[5] = {};
    int midr = (lr+br)/2;
    int midc = (lc+bc)/2;
    cnt[solve(lr, lc, midr, midc)]++;
    cnt[solve(midr+1, lc, br, midc)]++;
    cnt[solve(lr, midc+1, midr, bc)]++;
    cnt[solve(midr+1, midc+1, br, bc)]++;

    if(cnt[3] >= 2) return 3;
    else if(cnt[2] >= 2) return 2;
    else if(cnt[1] >= 1) return 1;
    else assert(0);
    return -1;
}

int main(void){
    int Q; cin >> Q;
    while(Q--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> arr[i][j];
            }
        }

        cout << solve(1, 1, n, n) << "\n";

    }

    return 0;
}