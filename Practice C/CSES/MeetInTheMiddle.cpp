#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll S,a[45],ans;
unordered_map<ll, int> mp(1e6+10);

int main(void){
    cin >> n >> S;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int lim = n/2;
    for(int bit = 0; bit < 1<<lim; bit++){
        ll sum = 0;
        for(int i = 0; i < lim; i++){
            if(bit&(1<<i)) sum += a[i];
        }
        mp[sum]++;
    }

    /*cout << "ELEMENT\n";
    for(auto [val, cnt] : mp){
        cout << val << " " << cnt << "\n";
    }*/

    int lim2 = n-lim;
    //cout << lim << " " << lim2 << "\n";
    for(int bit = 0; bit < 1<<lim2; bit++){
        ll sum = 0;
        for(int i = 0; i < lim2; i++){
            if(bit&(1<<i)) sum += a[lim+i];
        }
        if(mp.count(S-sum))
            ans += mp[S-sum];
    }
    cout << ans << "\n";
}
