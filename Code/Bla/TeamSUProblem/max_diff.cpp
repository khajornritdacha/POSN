#include<bits/stdc++.h>
using namespace std;
multiset<int,greater<int>> ss;
int n,k;
main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        ss.insert(x);
    }
    for(int i=1; i<=k; i++){
        int k1=*ss.begin();
        ss.erase(ss.begin());
        int k2=*ss.begin();
        ss.erase(ss.begin());
        ss.insert(k1-k2);
    }
    cout << *ss.begin();
}
