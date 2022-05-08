#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int, int>;

int a[N],n,K;

bool chk(int R){
    int k = K;
    for(int i=1,mn=1; i<=n; i++){
        if(a[i+1]-a[mn] > 2*R){
            k--;
            mn = i+1;
        }
    }
    return (k >= 0);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    a[n+1] = 2e9+10;
    sort(a+1, a+n+1);
    int l=0, r=1e9, mid, ans;
    while(l <= r){
        mid = l+(r-l)/2;
        if(chk(mid)){
            //cout << mid << "\n";
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans;
}
