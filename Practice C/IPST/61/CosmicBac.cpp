#include <bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 1e5+10;
using ll = long long;
using pi = pair<long long, long long>;
int n;
ll L;
pi pos[N];
vector<pi> vec;
map<ll, ll> mp;

ll dis(pi A, pi B){
    return abs(A.first-B.first)+abs(A.second-B.second);
}

bool les(int A, int B, pi P){
    ll dA = dis(pos[A], P), dB = dis(pos[B], P);
    //cout << "LES : " << A << " " << B << " " << dA << " " << dB << "\n";
    //cout << "P : " << P.first << "\n";
    return (dA < dB or (dA == dB and A < B));
}

ll bil(ll l, ll r, int old, int ch){
    ll ans = -1;
    while(l <= r){
        ll mid = (l+r)>>1;
        if(les(ch, old, {mid, 0})){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

ll bir(ll l, ll r, int ch, int old){
    ll ans = -1;
    //cout << "BIR : " << l << " " << r << " " << ch << " " << old << " = ";
    while(l <= r){
        ll mid = (l+r)>>1;
        if(les(ch, old, {mid, 0})){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    //cout << ans << "\n";
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L;
    for(int i = 1; i <= n; i++){
        cin >> pos[i].first >> pos[i].second;
        pos[i].second += i;
        vec.emplace_back(pos[i].second, i);
    }
    sort(vec.begin(), vec.end());
    mp[0] = mp[L] = vec[0].second;
    for(int i = 1; i < n; i++){
        ll idx = vec[i].second, ridx, lidx, l, r;
        tie(r, ridx) = *(mp.lower_bound(pos[idx].first));
        tie(l, lidx) = *(--mp.upper_bound(pos[idx].first));
        ll cl = l, cr = r;
        if(DEBUG){
            cout << "------------\n";
            cout << "MAP\n";
            cout << idx << " " << ridx << " " << lidx << "\n";
            for(auto [val, idx] : mp){
                cout << val << " " << idx << "\n";
            }
            cout << "------------\n";
        }
        if(les(idx, ridx, {pos[idx].first, 0})){
            if(l != r){
                if(pos[idx].first < pos[ridx].first){
                    cl = l, cr = pos[idx].first;
                }else{
                    cl = pos[idx].first, cr = r;
                }
            }

            if(pos[idx].first < pos[ridx].first){
                mp.erase(l);
                mp.erase(l-1);
            }else{
                mp.erase(r);
                mp.erase(r+1);
            }
            if(cl != 0){
                //cout << "NOW : " << idx << "\n";
                ll nl,nlidx;
                tie(nl, nlidx) = *(--mp.lower_bound(cl));
                ll Ml = bil(nl, cl, nlidx, idx);
                mp[Ml-1] = nlidx;
                mp[Ml] = idx;
            }else{
                mp[cl] = idx;
            }
            if(cr != L){
                ll nr,nridx;
                tie(nr, nridx) = *(mp.upper_bound(cr));
                ll Mr = bir(cr, nr, idx, nridx);
                mp[Mr] = idx;
                mp[Mr+1] = nridx;
            }else{
                mp[cr] = idx;
            }
        }
    }
    vector<ll> ans(n+5);
    vector<pi> chua;
    for(auto [val, idx] : mp){
        chua.emplace_back(val, idx);
    }
    ll r = chua.back().first, pre = chua.back().second, l = r, ct = 1;
    chua.pop_back();
    while(!chua.empty()){
        if(chua.back().second != pre){
            ans[pre] = r-l+1;
            r = l = chua.back().first;
            pre = chua.back().second;
        }else{
            l = chua.back().first;
        }
        chua.pop_back();
    }
    ans[pre] = r-l+1;

    if(DEBUG){
        cout << "MAP\n";
        for(auto [val, idx] : mp){
            cout << val << " " << idx << "\n";
        }
        cout << "------------\n";
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
