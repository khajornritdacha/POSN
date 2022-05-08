#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n,m;
ll pw,base = 2011;
unordered_map<ll, int> mp(1000010);

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        ll tmp = 0;
        for(int j = 0; j < m; j++){
            tmp = (tmp*base)+str[j];
        }
        mp[tmp] = i;
    }

    /*for(auto [val, idx] : mp) cout << val << " " << idx << "\n";
    cout << "\n";*/

    pw = 1;
    for(int i = 0; i < m; i++) pw *= base;

    int Q; cin >> Q;
    while(Q--){
        int sz; cin >> sz;
        string str; cin >> str;
        set<int> ans;
        ll cur = 0;
        for(int i = 0; i < sz; i++){
            if(i >= m){ ///check
                cur -= str[i-m]*pw;
            }
            cur += str[i];
            if(mp.count(cur)){
                ans.insert(mp[cur]);
            }
            cur *= base;
        }
        if(ans.size() == 0){ cout << "OK\n"; }
        else{
            for(int an : ans)
                cout << an << " ";
            cout << "\n";
        }
    }
    return 0;
}
