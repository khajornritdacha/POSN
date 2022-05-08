#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int, int>;

pi a[N];
int n,m;

bool chk(int D){
    int i=1, la=-1e18-10, k = n;
    while(i <= m){
        int now = la+D;
        if(now <= a[i].second){
            la = max(now, a[i].first);
            k--;
        }else{
            i++;
        }
    }
    return (k <= 0);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+m+1);
    int l = 1, r = 1e18+10, mid, ans;
    while(l <= r){
        mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout << ans << "\n";
}
