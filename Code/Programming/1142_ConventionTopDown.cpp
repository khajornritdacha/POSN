#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int seg[4*N],lazy[4*N],n,K,sl[N],sr[N];
unordered_map<int, int> idx;
vector<int> vec;

void up(int wl, int wr, int val = 1, int l = 1, int r = vec.size(), int node = 1){
    if(lazy[node]){
        seg[node] += lazy[node];
        if(l != r){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(wl > wr or r < wl or l > wr)
        return;

    if(wl <= l and r <= wr){
        seg[node] += val;
        if(l != r){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }

    int mid = (l+r)/2;
    up(wl, wr, val, l, mid, node*2);
    up(wl, wr, val, mid+1, r, node*2+1);
    seg[node] = max(seg[2*node], seg[2*node+1]);
}

int qq(int wl, int wr, int l = 1, int r = vec.size(), int node = 1){
    if(lazy[node]){
        seg[node] += lazy[node];
        if(l != r){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(wl > wr or r < wl or l > wr)
        return -2e9;

    if(wl <= l and r <= wr)
        return seg[node];

    int mid = (l+r)/2;
    return max(qq(wl, wr, l, mid, node*2), qq(wl, wr, mid+1, r, node*2+1));
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> sl[i] >> sr[i];
        vec.emplace_back(sl[i]);
        vec.emplace_back(sr[i]);
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end())-vec.begin());
    for(int i=0; i<vec.size(); i++)
        idx[vec[i]] = i+1;

    for(int i=1; i<=n; i++){
        if(qq(idx[sl[i]], idx[sr[i]]) < K){
            up(idx[sl[i]], idx[sr[i]]);
            cout << "yes";
        }else{
            cout << "no";
        }
        cout << "\n";
    }
}
