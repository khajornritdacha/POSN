#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;

void solve(){
    int co[5] = {};
    for(int i = 0; i < 5; i++) co[i] = INF;

    for(int i = 1; i <= 3; i++){
        for(int c = 1; c <= 4; c++){
            int x; cin >> x;
            co[c] = min(co[c], x);
        }
    }

    // cout << co[1] << " " << co[2] << " " << co[3] << " " << co[4] << "\n";
    
    int req = 1e6, res[5] = {};
    for(int c = 1; c <= 4; c++){
        if(req > co[c]){
            res[c] = co[c];
            req -= co[c];
            co[c] = 0;
        } else {
            res[c] = req;
            co[c] -= req;
            req = 0;
        }
    }

    if(req > 0){
        cout << "IMPOSSIBLE\n";
    } else {
        cout << res[1] << " " << res[2] << " " << res[3] << " " << res[4] << "\n";
    }

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test_case; cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}