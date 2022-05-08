#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int fen[N],n,ans[N],sum;
vector<pair<int,int>> vec;
int qs(int idx){
    int res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}
void up(int idx, int val){
    while(idx <= n){
        fen[idx] += val;
        idx += idx&-idx;
    }
}
int lb(int val){
    int l=1,r=n,mid,ans=n;
    while(l <= r){
        mid = (l+r)/2;
        if(qs(mid) >= val){
            ans = min(ans, mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vec.emplace_back(1e9, 1e9);
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.emplace_back(x, i);
        sum += x;
    }
    sort(vec.rbegin(), vec.rend());
    for(int i=1; i<vec.size(); i++){
        up(i, vec[i].first);
    }
    for(int i=1; i<vec.size(); i++){
        up(i, -vec[i].first);
        int wa = (sum/2+1-vec[i].first);
        int pos = lb(wa);
        if(pos >= i)
            pos--;
        ans[vec[i].second] = pos;
        up(i, vec[i].first);
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] << "\n";
    }
}
