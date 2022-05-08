#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
map<int,int> cnt;
int n,K,a[N];

main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(cnt[K-a[i]])
            cnt[K-a[i]]--;
        else
            cnt[a[i]]++;
    }
    for(auto [key, val] : cnt){
        if(val > 0){
            cout << "Unpair : " << key << "\n";
        }
    }
}
