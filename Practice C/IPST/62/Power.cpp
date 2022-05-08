#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int,int>;

int n,m,P[N][2],C[N];
ll dp[N][2],seg[2][4*N], INF = 1e18;

void up(int k, int idx, ll val, int l = 1, int r = n, int node = 1){
    if(l == r){
        seg[k][node] = max(seg[k][node], val);
        return;
    }

    int mid = (l+r)>>1;
    if(idx <= mid) up(k, idx, val, l, mid, node<<1);
    else up(k, idx, val, mid+1, r, node<<1|1);

    seg[k][node] = max(seg[k][node<<1], seg[k][node<<1|1]);
    return;
}

ll ask(int k, int a, int b, int l = 1, int r = n, int node = 1){
    if(a > b or r < a or b < l) return -INF;
    if(a <= l and r <= b) return seg[k][node];

    int mid = (l+r)>>1;
    return max(ask(k, a, b, l, mid, node<<1), ask(k, a, b, mid+1, r, node<<1|1));
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < 4*N; i++) seg[0][i] = seg[1][i] = -INF;

    ll ans = -INF;
    for(int i = 1; i <= m; i++){
        cin >> P[i][0] >> P[i][1] >> C[i];

        for(int b : {0, 1}){
            dp[i][b] = max({dp[i][b],
                            1ll*C[i], //choose this one as the first one 
                            ask(0, P[i][!b], n)+P[i][!b] + C[i], //choose the one from above
                            ask(1, 1, P[i][!b]-1)-P[i][!b] + C[i] }); //choose the one from below
        }

        //cout << "CHK : " << ask(0, P[i][0], n) << " " << ask(0, P[i][0], n)-P[i][0] << "\n";
        //cout << "CHK2 : " << ask(1, 1, P[i][0]-1) << " " << 

        for(int b : {0, 1}){
            up(1, P[i][b], dp[i][b]+P[i][b]);
            up(0, P[i][b], dp[i][b]-P[i][b]);
        }

        ans = max({ans, dp[i][0], dp[i][1]});
        cout << ans << "\n";
    }
    return 0;
}