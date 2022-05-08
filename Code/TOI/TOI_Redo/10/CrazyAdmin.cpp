#include <bits/stdc++.h>
using namespace std;

const int N = 110;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int M,n,a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int l = 0, r = 1e7, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;

        int cnt = 0, sum = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > mid){
                cnt = 1e9;
                break;
            }

            if(a[i] + sum > mid){
                sum = 0;
                cnt++;
            }

            sum += a[i];
        }

        //cout << mid << " " << cnt << " " << sum << "\n";
        if (cnt < M){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << "\n";

    return 0;   
}