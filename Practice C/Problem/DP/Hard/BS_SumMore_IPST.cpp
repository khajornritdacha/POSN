#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
ll qs[N],K,mx=-1e18,n;
vector<ll> fen,vec;
set<ll> ss;
ll query(int i){
    ll tmp = 0;
    if(i==0) return 0;
    while(i>=1){
        tmp += fen[i];
        i-=(i&-i);
    }
    return tmp;
}
void up(int i, int val){
    if(i==0) return;
    while(i<=fen.size()){
        fen[i] += val;
        i+=(i&-i);
    }
}
bool chk(ll m){
    fen.clear();
    fen.resize(vec.size()+10, 0);
    int idx = lower_bound(vec.begin(), vec.end(), 0LL)-vec.begin();
    up(idx, 1);
    ll ans = 0;
    for(int i=1; i<=n; i++){
        idx = upper_bound(vec.begin(), vec.end(), qs[i]-m)-vec.begin();
        ans+=query(idx-1);
        idx = lower_bound(vec.begin(), vec.end(), qs[i])-vec.begin();
        up(idx, 1);
    }
    return ans>=K;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    vec.emplace_back(0);
    vec.emplace_back(-1e18);
    for(int i=1; i<=n; i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
        vec.emplace_back(qs[i]);
    }
    sort(vec.begin(), vec.end());
    ll l=-1e15, r=1e15, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(chk(mid)){
            l = mid+1;
            mx = max(mx, mid);
        }else{
            r = mid-1;
        }
    }
    cout << mx << "\n";
}
