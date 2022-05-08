#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
using ll = long long;
using pi = pair<ll, ll>;


int main(void){
    int n; cin >> n;
    int a[n+5] = {};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> lis;
    for(int i = 1; i <= n; i++){
        int k = lower_bound(lis.begin(), lis.end(), a[i])-lis.begin();
        if(k == lis.size()) lis.emplace_back(a[i]);
        else lis[k] = a[i];
    }
    cout << lis.size() << "\n";
    return 0;
}
