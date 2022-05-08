#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n,a[N],qs[N],Q;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
    }

    int mn = 2e9;
    map<int,int> mp;
    for(int i = n; i >= 1; i--){
        if(qs[i] < mn){
            mp[qs[i]] = i;
            mn = qs[i];
        }
    }
    
    while(Q--){
        int x; cin >> x;
        auto it = mp.upper_bound(x);
        if(it != mp.begin()){
            it--;
            cout << it->second << "\n";
        }else{
            cout << "0\n";
        }
    }

    return 0;
}