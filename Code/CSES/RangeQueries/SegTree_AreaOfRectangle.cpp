#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6+10;

///https://cses.fi/problemset/task/1741

struct DATA{
    int x,y1,y2,val;
    bool operator < (const DATA &other){
        return x < other.x;
    }
};

int laz[4*N],n,K=1e6;
ll seg[4*N];
vector<DATA> event;

void up(int a, int b, int val, int l = 1, int r = 2*K, int node = 1){
    if(r < a or l > b) return;
    if(a <= l and r <= b){
        laz[node] += val;
        seg[node] = (laz[node]) ? r-l+1 : (r == l) ? 0 : seg[node<<1]+seg[node<<1|1];
        return;
    }
    int mid = (l+r)>>1;
    up(a, b, val, l, mid, node<<1), up(a, b, val, mid+1, r, node<<1|1);
    seg[node] = (laz[node]) ? r-l+1 : (r == l) ? 0 : seg[node<<1]+seg[node<<1|1];
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        event.push_back({x1, y1+K+1, y2+K, 1});
        event.push_back({x2, y1+K+1, y2+K, -1});
    }
    sort(event.begin(), event.end());

    ll res = 0;
    for(int i = 0; i < event.size(); i++){
        DATA tmp = event[i];
        if(i > 0)
            res += (event[i].x-event[i-1].x)*seg[1];
        //cout << "I : " << i << " = " << seg[1] << "\n";
        //cout << tmp.x << " " << tmp.y1 << " " << tmp.y2 << " " << tmp.val << "\n";
        up(event[i].y1, event[i].y2, event[i].val);
    }

    cout << res << "\n";
    return 0;
}
