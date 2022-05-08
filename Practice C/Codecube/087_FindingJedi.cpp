#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
int n,M;
long long ans;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }

    for(auto &[key, val] : mp){
        if(key > M/2) break;
        int wa = M-key;
        if(wa == key){
            ans += (1ll*val*(val-1))/2;
        }else{
            if(mp.find(wa) != mp.end()){
                ans += 1ll*mp[wa]*val;
            }
        }
        //cout << key << " -> " << ans << "\n";
    }
    cout << ans;
}
