#include<bits/stdc++.h>
using namespace std;


using pi = pair<int,int>;
const int N = 5e4+10;
vector<pi> vec;
int n,K,ans[N];


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        ans[i] = i;
    }
    for(int i=1; i<=K; i++){
        int t,u;
        cin >> u >> t;
        vec.emplace_back(t, u);
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++){
        int u = vec[i].second;
        swap(ans[u], ans[u+1]);
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] << "\n";
    }
}
