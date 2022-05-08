#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;

int T,Q;
map<vector<pi>, int> mp;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T >> Q;
    while(T--){
        int n; cin >> n;
        vector<pi> G;
        for(int i = 1; i < n; i++){
            int u,v; cin >> u >> v;
            if(u > v) swap(u, v);
            G.emplace_back(u, v);
        }
        sort(G.begin(), G.end());
        mp[G]++;
    }

    while(Q--){
        int n; cin >> n;
        vector<pi> G;
        for(int i = 1; i < n; i++){
            int u,v; cin >> u >> v;
            if(u > v) swap(u, v);
            G.emplace_back(u, v);
        }
        sort(G.begin(), G.end());
        if(mp.find(G) != mp.end()) cout << mp[G] << "\n";
        else cout << "0\n";
    }

    return 0;
}
