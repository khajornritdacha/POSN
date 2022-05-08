#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],pre[N],n;
int qs(int l, int r){
    if(r < l) return 0;
    if(l <= 0) return pre[r];
    return pre[r]-pre[l-1];
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> pre[i];
        pre[i]+=pre[i-1];
    }
    for(int i=1; i<=n; i++){
        int l=1, r=(n-1)/2, res = 0;
        while(l <= r){
            int mid = (l+r)/2;
            int ld = qs(max(1, i-mid), i-1);
            int rd = qs(i+1, min(n, i+mid));
            if(i-mid < 1){
                ld += qs(n-mid+i, n);
            }
            if(i+mid > n){
                rd += qs(1, i+mid-n);
            }
            if(ld+rd <= a[i]){
                res = max(res, mid);
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        cout << res*2 << " ";
    }
}
