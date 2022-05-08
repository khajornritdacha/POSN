#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
unordered_map<int,int> mp;
void gen(){
    for(int i=2; i*i<=1e8; i++){
        int cnt = 2;
        //cout << i << "\n";
        for(int j=i*i; j<=1e8; j*=i){
            mp[j] = max(cnt, mp[j]);
            cnt++;
        }
    }
}
main(){
    gen();
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(mp.find(x) != mp.end())
            cout << mp[x] << "\n";
        else
            cout << "NO\n";
    }
}
