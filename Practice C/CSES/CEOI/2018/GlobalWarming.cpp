#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, D, arr[N], seg[2][4*N], dp[N][2];

//dp(i, b) := LIS that ends with arr[i] and boolean b whether used increment or not
//dp(i, 0) = 1+max(dp(j, 0)); arr[j] < arr[i], j < i
//dp(i, 1) = 1+max(dp(j, 0), dp(k, 1)); arr[j] < arr[i]+D, j < i, arr[k] < arr[i], k < i

struct DATA{
    int v, idx, cd;
};

vector<DATA> order;

void up(int idx, int cd, int l = 1, int r = n, int node = 1){
    if(l == r){
        seg[cd][node] = max(seg[cd][node], dp[idx][cd]);
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, cd, l, mid, node<<1);
    else up(idx, cd, mid+1, r, node<<1|1);
    seg[cd][node] = max(seg[cd][node<<1], seg[cd][node<<1|1]);
}

int ask(int a, int b, int cd, int l = 1, int r = n, int node = 1){
    if(a > b or b < l or a > r) return 0;
    if(a <= l and r <= b) return seg[cd][node];
    int mid = (l+r)>>1;
    return max(ask(a, b, cd, l, mid, node<<1), ask(a, b, cd, mid+1, r, node<<1|1));
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> D;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        order.push_back({arr[i], i, 0});
        order.push_back({arr[i]+D, i, 1});
    }

    sort(order.begin(), order.end(), [&](const DATA &A, const DATA &B){
        if(A.v != B.v) return A.v < B.v;
        return A.idx > B.idx;
    });

    for(DATA cur : order){
        dp[cur.idx][cur.cd] = 1+ask(1, cur.idx-1, 0);
        if(cur.cd == 1)
            dp[cur.idx][cur.cd] = max(dp[cur.idx][cur.cd], 1+ask(1, cur.idx-1, 1));
        up(cur.idx, cur.cd);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max({ans, dp[i][0], dp[i][1]});
    cout << ans << "\n";



    return 0;
}