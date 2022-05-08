#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int fen[N],n;
long long ans;
void up(int idx, int val){
    while(idx <= n){
        fen[idx] += val;
        idx += idx&-idx;
    }
}
int qs(int idx){
    int res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}
vector<pair<int,int>> vec;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x;
        vec.emplace_back(x,i);
    }
    //cout << sizeof(vec);
    sort(vec.rbegin(), vec.rend());
    vec.emplace_back(0,0);
    for(int i=0; i<n; i++){
        ans += qs(vec[i].second);
        //cout << i << " " << vec[i].first << " " << vec[i].second << " " << qs(vec[i].second) << "\n";
        up(vec[i].second, 1);
    }
    cout << ans;
}
