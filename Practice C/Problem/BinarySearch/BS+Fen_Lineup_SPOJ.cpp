#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;

int n,s[N],h[N],ans[N],fen[N];
///https://www.spoj.com/problems/KOILINE/
///find the current s[i]+1th number from the rest h
void up(int idx, int val){
    if(idx == 0) return;
    while(idx <= n){
        fen[idx] += val;
        idx += idx&-idx;
    }
}

int qs(int idx){
    int res = 0;
    if(idx == 0) return 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> h[i];
        up(i, 1);
    }
    sort(h+1, h+n+1);
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    for(int i=n; i>=1; i--){
        int l=1,r=n,res = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(qs(mid) >= s[i]+1){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        up(res, -1);
        ans[i] = h[res];
    }
    for(int i=1; i<=n; i++)
        cout << ans[i] << "\n";
}
