#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int,int>;


ll n,m,K;
vector<pi> vec;

int bi(int val){
    int l = 0, r = vec.size()-1, res = vec.size();
    while(l <= r){
        int mid = (l+r)>>1;
        if(vec[mid].first > val){
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return res;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> K;
    vec.emplace_back(0, 0);
    for(int i = 1, co = 0; i <= m; i++){
        int x; cin >> x;
        co = !co;
        vec.emplace_back(x, co);
    }

    int ans = m;
    for(int i = 1; i <= K; i++){
        ll a, c; cin >> a >> c;
        c = !c;
        int k = bi(a) - 1;

        assert(k >= 0);
        int lc = vec[k].second, rc = -1;

        if(k+1 < vec.size()){
            if(a + 1 == vec[k+1].first){
                rc = vec[k+1].second;
            } else {
                rc = lc;
            }
        }

        //cout << lc << " " << rc << " " << c << "\n";

        if(lc == rc){
            ans += (c == lc ? 0 : 2);
        } else {
            if(rc == -1){
                if(a == n){
                    ans += (c != lc);
                } else { //rc == -1
                    ans += (c == lc ? 0 : 2);
                }
            } //rc != -1 and lc != rc -> nothing happens
        }
    }

    cout << ans << "\n";
    
    return 0;
}