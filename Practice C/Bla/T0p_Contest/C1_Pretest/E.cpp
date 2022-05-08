#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 2e5+5;
int n,K,a[N],qs[N],fen[N];
vector<int> vec;
map<int,int> ump;

void up(int idx, int val){
    while(idx <= vec.size()){
        fen[idx] += val;
        idx += idx&-idx;
    }
}

int sum(int idx){
    if(idx <= 0) return 0;
    int res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
        vec.emplace_back(qs[i]);
    }
    vec.emplace_back(0);
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end())-vec.begin());
    for(int i=0; i<vec.size(); i++){
        ump[vec[i]] = i+1;
    }

    if(DEBUG){
        for(int i=0; i<vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
        for(auto [key, val] : ump){
            cout << key << " " << val << "\n";
        }
    }
    int ans = 0;
    up(ump[0], 1);
    for(int i=1; i<=n; i++){
        int k = upper_bound(vec.begin(), vec.end(), qs[i]-K)-vec.begin()-1;
        if(DEBUG){
            cout << "I : " << i << " = " << qs[i] << "\n";
            cout << k << " " << vec[k] << " " << sum(vec[k]) << "\n";
            cout << sum(ump[vec.back()]) << " " << sum(ump[vec[k]]) << "\n";
        }
        ans += sum(ump[vec.back()])-sum(ump[vec[k]]);
        up(ump[qs[i]], 1);
    }
    cout << ans << "\n";
}
