#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

//abs(si-sj) <= ti-tj
//tj-ti <= si-sj <= ti-tj
//both conditions must be hold : si+ti >= sj+tj and si-ti <= sj-tj
//dp(i) = max(dp(j)) + 1

struct DATA{
    int s,t;
};

vector<DATA> order;
int seg[4*N],n;
map<int,int> idx;

void up(int ii, int val, int l = 1, int r = idx.size(), int node = 1){
    if(l == r){
        seg[node] = max(seg[node], val);
        return;
    }
    int mid = (l+r)>>1;
    if(ii <= mid) up(ii, val, l, mid, node*2);
    else up(ii, val, mid+1, r, node*2+1);
    seg[node] = max(seg[node*2], seg[node*2+1]);
    return;
}

int ask(int a, int b, int l = 1, int r = idx.size(), int node = 1){
    if(a > b or r < a or b < l) return -INF;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return max(ask(a, b, l, mid, node*2), ask(a, b, mid+1, r, node*2+1));
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s0; cin >> n >> s0;
    order.resize(n+1);
    order[0] = {s0, 0};
    for(int i = 1; i <= n; i++){
        int s, t; cin >> s >> t;
        order[i] = {s, t};
    }

    sort(order.begin(), order.end(), [&](const DATA &A, const DATA &B){
        if(A.s + A.t != B.s + B.t) return A.s+A.t < B.s+B.t;
        return A.t < B.t;
    });

    // for(int i = 0; i <= n; i++){
    //     cout << order[i].s + order[i].t << " " << order[i].s << " " << order[i].t << "\n";
    // }
    // cout << "\n";

    vector<int> chua(n+1);
    for(int i = 0; i <= n; i++){
        chua[i] = order[i].s-order[i].t;
    }
    sort(chua.begin(), chua.end()); chua.resize(unique(chua.begin(), chua.end())-chua.begin());

    for(int i = 0; i < chua.size(); i++){
        idx[chua[i]] = i+1; //map
        // cout << chua[i] << " " << i+1 << "\n";
    }
    // cout << "\n";

    for(int i = 0; i <= 4*idx.size(); i++) seg[i] = -INF;

    for(int i = 0; i <= n; i++){
        int s = order[i].s, t = order[i].t;
        if(t == 0){
            up(idx[s-t], 0);
        } else {
            int k = (idx.lower_bound(s-t))->second;
            // cout << i << " " << k << " " << ask(k, idx.size()) << "\n";
            int tmp = ask(k, idx.size()) + 1;
            if(tmp >= 0)
                up(k, tmp);
        }
    }

    cout << ask(1, idx.size());

    return 0;
}