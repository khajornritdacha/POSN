#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using pi = pair<int,int>;
int n,m,q;
vector<pi> vec;
map<int,int> mp;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        mp[x]++;
        mp[x+y]--;
    }

    int lc = 0, lp = 1, now=0;
    for(auto &[key,val] : mp){
        now+=val;
        if(DEBUG){
            cout << "NOW : "<< now << " " <<key << " " << val << " " << lp << " " << key-lp << "\n";
        }
        if((now+2)%2 == lc)
            continue;
        vec.emplace_back(lp, key-lp);
        lp = key;
        lc = (now+2)%2;
    }

    if(vec.empty())
        vec.emplace_back(1, n);

    int tmp = vec.back().first+vec.back().second;
    if(tmp-1 != n){
        vec.emplace_back(tmp, n-tmp+1);
    }

    if(DEBUG){
        cout << "VEC : \n";
        for(auto [x,y] : vec){
            cout << x << " " << y << "\n";
        }
    }

    for(int i=1; i<=q; i++){
        int x;
        cin >> x;
        int k = upper_bound(vec.begin(), vec.end(), make_pair(x,1000000000))-vec.begin();
        if(DEBUG){
            cout << "K : " << k << "\n";
        }
        if(k!=0)
            k--;
        cout << vec[k].second << "\n";
    }
}
