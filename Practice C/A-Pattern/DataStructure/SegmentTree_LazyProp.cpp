#include<bits/stdc++.h>
using namespace std;
int t[200010],n,q,h,d[100010];
void apply(int i, int val){
    t[i] += val;
    if(i < n)
        d[i] += val;
}
void build(int i){
    while(i > 1){
        i/=2;
        t[i] = max(t[i*2], t[i*2+1]) + d[i];
    }
}
void push(int i){
    for(int s = h; s; s--){
        int now = i >> s;
        if(d[now] != 0){
            apply(now*2, d[now]);
            apply(now*2+1, d[now]);
            d[now] = 0;
        }
    }
}
void up(int l, int r, int val){
    l += n-1, r+=n-1;
    int l0 = l, r0 = r;
    for(; l<=r; l/=2, r/=2){
        if(l%2){
            apply(l++, val);
        }
        if(r%2 == 0)
            apply(r--, val);
        }
    build(l0);
    build(r0);
}
int qs(int l, int r){
    l +=n-1, r+=n-1;
    int mx = 0;
    push(l);
    push(r);
    for(; l<=r; l/=2,r/=2){
        if(l%2)
            mx = max(mx, t[l++]);
        if(r%2 == 0)
            mx = max(mx, t[r--]);
    }
    return mx;
}
main(){
    cin >> n;
    h = sizeof(int)*8-__builtin_clz(n);
    /*for(int i=1; i<=n; i++){
        cin >> t[i+n-1];
    }
    for(int i=n-1; i; i--){
        t[i] = t[2*i]+t[2*i+1];
    }*/
    cin >> q;
    while(q--){
        int x,l,r;
        int val;
        cin >> val >> l >> r;
        up(l, r, val);
        for(int i=1; i<=n; i++){
            cout << "QS [1," << i << "] = " << qs(1,i) << "\n";
        }
        cout << qs(3, 5) << "\n";
    }
}
