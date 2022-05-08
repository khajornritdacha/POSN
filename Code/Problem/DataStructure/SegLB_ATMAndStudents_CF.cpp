//https://codeforces.com/contest/1611/problem/F
//Lowerbound finding the rightmost index r such that qs[k]-qs[l-1] >= -S for all l <= k <= r
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, S, arr[N];
long long seg[4*N], qs[N], INF = 1e18;


void up(int idx, long long val, int l = 1, int r = n, int node = 1){
    if(l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, val, l, mid, node<<1);
    else up(idx, val, mid+1, r, node<<1|1);
    seg[node] = min(seg[node<<1], seg[node<<1|1]);
}

int ask(int a, int b, int l = 1, int r = n, int node = 1){
    if(a > b or b < l or a > r) return -1;
    if(l == r) return (qs[a-1]-S <= qs[l] ? l : -1);

    int mid = (l+r)>>1, lc = node<<1, rc = node<<1|1;
    if(qs[a-1]-S <= seg[lc]) return max(mid, ask(a, b, mid+1, r, rc));
    return ask(a, b, l, mid, lc); 
}

void TC(){
    cin >> n >> S;
    for(int i = 0; i <= 4*n; i++) seg[i] = INF;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        qs[i] = qs[i-1] + arr[i];
        up(i, qs[i]);
    }

    int ar = -1, al = 0;
    for(int l = 1; l <= n; l++){
        int r = ask(l, n);
        // cout << l << " " << r << "\n";
        if(r != -1 and r-l+1 > ar-al+1){
            ar = r, al = l;
        }
        up(l, INF);
    }

    if(ar == -1) cout << "-1\n";
    else cout << al << " " << ar << "\n";

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) TC();

    return 0;
}