#include<bits/stdc++.h>
using namespace std;

int n,mx;
map<int,int> mp;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto &key : mp){
        mx = max(mx, key.second);
    }
    for(auto &key : mp){
        if(mx == key.second){
            cout << key.first;
            return 0;
        }
    }
}
