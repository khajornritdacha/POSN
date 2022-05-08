#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;
ll ans = 2e18,lcm[15];
vector<int> pos[15];
string str[15];
void solve(int lv=1, ll now=1){
    //cout << lv << " ";
    if(lv == n+1){
        ans = min(ans, now);
        return;
    }
    for(ll i=0; i<=lcm[lv+1] && i<ans; i+=lcm[lv]){
        if(binary_search(pos[lv].begin(), pos[lv].end(), (i+now)%str[lv].size()) && now+i < ans){
            solve(lv+1, now+i);
        }
    }
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    lcm[1] = 1;
    for(int i=1; i<=n; i++){
        cin >> str[i];
        for(int j=0; j<str[i].size(); j++){
            if(str[i][j]-'0' == t)
                pos[i].emplace_back(j);
        }
        lcm[i+1] = lcm[i]/__gcd(lcm[i], (ll)str[i].size())*str[i].size();
    }
    solve();
    cout << ans << "\n";
}
