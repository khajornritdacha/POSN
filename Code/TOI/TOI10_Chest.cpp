#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;
int m,n,mx,ans,cnt[15];
map<int, vector<int>> mp;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        int x,l,r;
        cin >> x >> l >> r;
        l++,r++;
        if(x == 4){
            mp[l].emplace_back(2), mp[r+1].emplace_back(-2);
            mp[l].emplace_back(2), mp[r+1].emplace_back(-2);
        }else if(x == 6){
            mp[l].emplace_back(2), mp[r+1].emplace_back(-2);
            mp[l].emplace_back(3), mp[r+1].emplace_back(-3);
        }else if(x == 8){
            mp[l].emplace_back(2), mp[r+1].emplace_back(-2);
            mp[l].emplace_back(2), mp[r+1].emplace_back(-2);
            mp[l].emplace_back(2), mp[r+1].emplace_back(-2);
        }else if(x == 9){
            mp[l].emplace_back(3), mp[r+1].emplace_back(-3);
            mp[l].emplace_back(3), mp[r+1].emplace_back(-3);
        }else if(x == 10){
            mp[l].emplace_back(2), mp[r+1].emplace_back(-2);
            mp[l].emplace_back(5), mp[r+1].emplace_back(-5);
        }else{
            mp[l].emplace_back(x), mp[r+1].emplace_back(-x);
        }
    }
    mp[1].emplace_back(1);
    mp[n+1].emplace_back(-1);
    auto it1 = mp.begin();
    auto it2 = mp.begin();
    for(; it1!=mp.end(); it1++){
        it2++;
        int wa = it1->first;
        vector<int> vec = it1->second;
        if(wa > n) break;
        for(int v : vec){
            if(v<0) cnt[-v]--;
            else cnt[v]++;
        }
        int now = 1;
        for(int i=2; i<=10; i++){
            if(cnt[i] > 0)
                now*=(cnt[i]+1);
        }
        if(DEBUG){
            cout << "NOW : " << wa << " " << now << "\n";
            sort(vec.begin(), vec.end());
            for(int v : vec)
                cout << v << " ";
            cout << "\n";
        }
        if(now > mx){
            mx = now;
            ans = 0;
        }
        if(now == mx){
            ans += it2->first-wa;
        }
    }
    cout << mx << " " << ans;
}
