#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
using ll = long long;
using lb = long double;

int n,ss;
vector<pair<int,int>> vx,vy;

///The optimal location is on position (median of x, median of y)

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x,y,s; cin >> x >> y >> s;
        vx.emplace_back(x, s);
        vy.emplace_back(y, s);
        ss += s;
    }

    sort(vx.begin(), vx.end()); sort(vy.begin(), vy.end());

    int med = (ss+1)/2, medx = -2e9, medy = -2e9, tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += vx[i].second;
        if(tmp >= med){
            medx = vx[i].first;
            break;
        }
    }
    tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += vy[i].second;
        if(tmp >= med){
            medy = vy[i].first;
            break;
        }
    }

    //cout << medx << " " << medy << "\n";

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += 1ll*abs(medx-vx[i].first)*vx[i].second + 1ll*abs(medy-vy[i].first)*vy[i].second;
    }
    cout << ans << "\n";
    return 0;
}
