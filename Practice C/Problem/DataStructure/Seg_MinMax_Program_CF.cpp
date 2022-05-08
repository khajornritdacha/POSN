#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
///https://codeforces.com/contest/1473/problem/D
struct DATA{
    int mx,mn;
};

int n,a[N],qs[N],Q;
DATA seg[4*N];

void up(int idx, int val, int l=1, int r=n, int node=1){
    if(l == r){
        seg[node].mx = seg[node].mn = val;
        return;
    }
    int mid = (l+r)/2;
    if(idx <= mid)
        up(idx, val, l, mid, node*2);
    else
        up(idx, val, mid+1, r, node*2+1);
    seg[node].mx = max(seg[node*2].mx, seg[node*2+1].mx);
    seg[node].mn = min(seg[node*2].mn, seg[node*2+1].mn);
}

int qq(int st, int ed, int code, int l=1, int r=n, int node=1){
    if(st > ed or ed < l or st > r){
        if(code)
            return 1e9;
        return -1e9;
    }
    if(st <= l and r <= ed){
        if(code)
            return seg[node].mn;
        return seg[node].mx;
    }
    int mid = (l+r)/2;
    if(code)
        return min(qq(st, ed, code, l, mid, node*2), qq(st, ed, code, mid+1, r, node*2+1));
    else
        return max(qq(st, ed, code, l, mid, node*2), qq(st, ed, code, mid+1, r, node*2+1));
}

void test_case(){
    cin >> n >> Q;
    for(int i=0; i<=4*n; i++){
        seg[i].mn = 1e9;
        seg[i].mx = -1e9;
    }
    for(int i=1; i<=n; i++){
        char c;
        cin >> c;
        if(c == '-')
            a[i] = -1;
        else
            a[i] = 1;
        qs[i] = qs[i-1]+a[i];
        up(i, qs[i]);
    }

    if(DEBUG){
        printf("QUICKSUM : ");
        for(int i=1; i<=n; i++){
            printf("%d ", qs[i]);
        }
        printf("\n");
    }

    while(Q--){
        int l, r;
        cin >> l >> r;
        int sum = qs[r]-qs[l-1];
        int mx = max( max(0ll, qq(1, l-1, 0)), qq(r+1, n, 0)-sum);
        int mn = min( min(0ll, qq(1, l-1, 1)), qq(r+1, n, 1)-sum);

        if(DEBUG){
            printf("QMX : %d %d\n", qq(1, l-1, 0), qq(r+1, n, 0));
            printf("QMN : %d %d\n", qq(1, l-1, 1), qq(r+1, n, 1));
            printf("MX : %d\nMN : %d\n", mx, mn);
            printf("SUM : %d\n", sum);
            printf("ANS : ");
        }

        cout << mx-mn+1 << "\n";
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
