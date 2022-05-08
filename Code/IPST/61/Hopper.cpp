#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 3010;

int n,M,seg[8*N];
vector<pair<int,int>> vec;

void up(int idx, int val, int l = 1, int r = 2*n, int node = 1){
    if(l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, val, l, mid, node<<1);
    else up(idx, val, mid+1, r, node<<1|1);
    seg[node] = max(seg[node<<1], seg[node<<1|1]);
    return;
}

int ask(int a, int b, int l = 1, int r = 2*n, int node = 1){
    if(r < a or l > b) return 0;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return max(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

bool chk(int K){
    //cout << "K = " << K << "\n";
    for(int i = 0; i<=8*n; i++) seg[i] = 0;
    queue<pair<int,int>> qq;
    int mx = 0, dp[n] = {};
    for(int i = 0; i < n; i++){
        int idx = vec[i].second;
        if(i != 0 and vec[i].first != vec[i-1].first){
            while(!qq.empty()){
                auto [u, v] = qq.front(); qq.pop();
                up(u, v), up(u+n, v);
            }
        }
        dp[i] = ask(idx+n-K, idx+n-1)+1;
        mx = max(mx, dp[i]);
        qq.emplace(idx, dp[i]);
    }
    return (mx > M);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M;
    if(M == 0){ cout << 0; return 0;}
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        vec.emplace_back(x, i);
    }
    sort(vec.begin(), vec.end());

    int l = 1, r = n-1, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;

        if(chk(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout << ans << "\n";
    return 0;
}
