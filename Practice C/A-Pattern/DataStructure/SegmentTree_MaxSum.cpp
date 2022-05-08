#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using ll = long long;
const int N = 400010;
ll sum[N],max_seg[N],pre[N],suf[N];
int n,q,ms;
void up(int i, int val){
    sum[i+=ms-1] = val;
    suf[i] = val;
    pre[i] = val;
    max_seg[i] = val;
    //cout << "I: " << i << "\n";
    for(i/=2; i; i/=2){
        max_seg[i] = max({max_seg[i*2], max_seg[i*2+1], suf[2*i]+pre[2*i+1]});
        pre[i] = max({sum[i*2] + pre[i*2+1], pre[i*2]});
        suf[i] = max({suf[i*2+1], suf[i*2] + sum[i*2+1]});
        sum[i] = sum[i*2]+sum[i*2+1];
    }
}
ll getans(){
    return max(max_seg[1], 0LL);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    ms = sizeof(int)*8-__builtin_clz(n);
    ms = 1 << ms;
    /*fill(pre, pre+n+ms+1, -1e18);
    fill(suf, suf+n+ms+1, -1e18);
    fill(max_seg, max_seg+n+ms+1, -1e18);*/
    if(DEBUG){
        cout << "MS : " << ms << "\n";
    }

    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        up(i, x);
    }
    if(DEBUG){
        for(int i=1; i<n+ms; i++){
            cout << "SUM from " << i << ": " << max_seg[i] << "\n";
        }
    }
    cout << getans() << "\n";
    while(q--){
        int idx,val;
        cin >> idx >> val;
        idx++;
        up(idx, val);
        cout << getans() << "\n";
    }
}
