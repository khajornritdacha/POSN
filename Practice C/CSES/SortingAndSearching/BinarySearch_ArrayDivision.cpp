#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int a[N],n,T;

bool chk(int K){
    int pre = 0, cnt = 1;
    for(int i=1; i<=n; i++){
        if(K < a[i]) return false;
        if(pre+a[i] > K){
            pre = 0;
            cnt++;
        }
        pre += a[i];
    }
    return cnt <= T;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);// freopen("sabotage.in", "r", stdin); freopen("sabotage.out", "w", stdout);
    cin >> n >> T;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int l = 1, r = 1e18, mid, ans;
    while(l <= r){
        mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
