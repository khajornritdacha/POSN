#include <bits/stdc++.h>
using namespace std;

///https://www.spoj.com/problems/AGGRCOW/

void test_case(){
    int n,C;
    cin >> n >> C;
    int a[n+5] = {};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int l = 0, r = 1e9, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        int la = a[1], num = C-1;
        for(int i = 2; i <= n; i++){
            if(a[i] >= la+mid){
                num--;
                la = a[i];
            }
            if(num == 0) break;
        }
        if(num == 0){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout << ans << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
