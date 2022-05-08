#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;

int n, Q;
vector<int> seg[4*N];

//MergeSortTree basically is a segment tree where each node stores elements in their respective range instead of a single value.
//https://otog.cf/problem
//problem id = 414 (Sort From LtoR Hard)

vector<int> merge(const vector<int> L, const vector<int> R){
    int i = 0, j = 0;
    vector<int> res;
    while(i < L.size() and j < R.size() and res.size() < 10){
        if(L[i] < R[j]){
            res.emplace_back(L[i]);
            i++;
        } else {
            res.emplace_back(R[j]);
            j++;
        }
    }
    while(i < L.size() and res.size() < 10){
        res.emplace_back(L[i]);
        i++;
    }
    while(j < R.size() and res.size() < 10){
        res.emplace_back(R[j]);
        j++;
    }
    return res;
}

void build(int l = 1, int r = n, int node = 1){
    if(l == r){
        int x; cin >> x;
        seg[node].emplace_back(x);
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = merge(seg[node<<1], seg[node<<1|1]);
}

vector<int> ask(int a, int b, int l = 1, int r = n, int node = 1){
    if(a > b or b < l or a > r) return {};
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return merge(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    build();

    while(Q--){
        int a, b; cin >> a >> b;
        a++, b++;
        vector<int> res = ask(a, b);
        for(int rr : res) cout << rr << " ";
        cout << "\n";
    }

    return 0;
}