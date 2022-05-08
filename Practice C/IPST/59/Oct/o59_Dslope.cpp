#include<bits/stdc++.h>
using namespace std;
const int N = 8e4+100;
int n,K,a[N],fen[N][50],mod=1e9-1;
vector<pair<int,int>> vec;
void up(int idx, int k, int val){
    if(idx == 0)
        return;
    while(idx <= n){
        fen[idx][k] = (fen[idx][k]+val)%mod;
        idx += idx&-idx;
    }
}
int sum(int idx, int k){
    int tmp = 0;
    while(idx){
        tmp = (tmp+fen[idx][k])%mod;
        idx -= idx&-idx;
    }
    return tmp;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        vec.emplace_back(a[i], i);
    }
    sort(vec.rbegin(), vec.rend());
    for(auto [val, idx] : vec){
        up(idx, 1, 1);
        for(int k=2; k<=K; k++)
            up(idx, k, sum(idx-1, k-1));
    }
    cout << sum(n, K);
}
