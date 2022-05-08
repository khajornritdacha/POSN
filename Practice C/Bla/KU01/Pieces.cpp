#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;

int L,W,n,m,Q,X[N],Y[N];
map<int,int> dx, dy;
map<ll, ll> ans;
vector<pair<ll, ll>> sx, sy;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> L >> W >> n >> m >> Q;

    for(int i = 1; i <= n; i++){
        cin >> X[i];
        dx[X[i]-X[i-1]]++;
    }
    dx[L-X[n]]++;

    for(int i = 1; i <= m; i++){
        cin >> Y[i];
        dy[Y[i]-Y[i-1]]++;
    }
    dy[W-Y[m]]++;

    for(auto [val, cnt] : dx) sx.emplace_back(val, cnt); ///since the sum of dx is equivalent to L therefore there can be at most sqrt(L) different dx
    for(auto [val, cnt] : dy) sy.emplace_back(val, cnt); ///also true for dy

    for(int i = 0; i < sx.size(); i++){ ///since A <= 1e5 and dx.size() is at most sqrt(1e9) = 3e4
        for(int j = 0; j < sy.size(); j++){ ///when dy is getting larger for loop of dx is less and it can be done in time
            if(sx[i].first * sy[j].first > 1e5) break;
            ans[sx[i].first * sy[j].first] += sx[i].second * sy[j].second;
        }
    }

    while(Q--){
        int A; cin >> A;
        if(ans.count(A)) cout << ans[A] << "\n";
        else cout << "0\n";
    }

    return 0;
}
