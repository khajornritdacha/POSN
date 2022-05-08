#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;
 
const int N = 1010;
using tu = tuple<int,int,int>;
using ll = long long;
using pi = pair<int,int>;
 
vector<pi> vec[N];
int n,X,a[N];
 
main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> X;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map<int, pi> mp;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(mp.count(X-a[i]-a[j])){
                auto [x, y] = mp[X-a[i]-a[j]];
                cout << x << " " << y << " " << i << " " << j << "\n";
                return 0;
            }
            vec[j].emplace_back(i, a[i]+a[j]);
        }
        for(auto [idx, val] : vec[i]) mp[val] = {idx, i}; //push the pair(i, j) after we are done for max(i, j)
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}