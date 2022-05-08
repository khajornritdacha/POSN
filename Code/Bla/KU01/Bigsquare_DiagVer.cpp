#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

const int MXN = 1e5+10;

int n, ans;
pi a[MXN];
map<int, pi> mp[2];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    for(int i = 1; i <= n; i++){
        for(int t = 0; t <= 1; t++){
            int tmp;

            if(t == 0) {
                tmp = a[i].first + a[i].second;            
            }else{
                tmp = a[i].first - a[i].second;
            }

            if(!mp[t].count(tmp)){
                mp[t][tmp] = {a[i].first, a[i].first};
            }else{
                mp[t][tmp].first = max(mp[t][tmp].first, a[i].first);
                mp[t][tmp].second = min(mp[t][tmp].second, a[i].first);
            }
        }
    }

    for(int t = 0; t <= 1; t++){
        for(auto [key, val] : mp[t]){
            ans = max(ans, val.first - val.second);
        }
    }

    cout << ans << "\n";
    return 0;
}