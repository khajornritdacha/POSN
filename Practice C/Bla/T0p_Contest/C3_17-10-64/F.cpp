#include <bits/stdc++.h>
using namespace std;

///https://www.spoj.com/problems/BRCKTS/

using ll = long long;
const int N = 3e4+10;

struct SEG{
    int LO,LC;
    bool ok;
};

int n;
bool str[N];
SEG seg[N*4];

void init(int idx, int node){
    //cout << idx << " " << node << " " << str[idx] << " ";
    if(!str[idx]){
        seg[node].LO = 1;
        seg[node].LC = 0;
        //cout << "OPEN\n";
    }else{
        seg[node].LO = 0;
        seg[node].LC = 1;
        //cout << "CLOSE\n";
    }
    seg[node].ok = false;
    return;
}

SEG Merge(SEG L, SEG R){
    SEG res;
    int mer = min(L.LO, R.LC);
    res.LO = L.LO-mer+R.LO;
    res.LC = L.LC+R.LC-mer;
    if(L.LC == 0 and R.LO == 0 and L.LO == R.LC){
        res.ok = true;
    }else{
        res.ok = false;
    }
    return res;
}

void build(int l = 1, int r = n, int node = 1){
    if(l == r){
        init(l, node);
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = Merge(seg[node<<1], seg[node<<1|1]);
    return;
}

void up(int idx, int l = 1, int r = n, int node = 1){
    if(l == r){
        str[l] = !str[l];
        init(l, node);
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, l, mid, node<<1);
    else up(idx, mid+1, r, node<<1|1);
    seg[node] = Merge(seg[node<<1], seg[node<<1|1]);
    return;
}


void pri(int l = 1, int r = n, int node = 1){
    if(l == r){
        cout << "L&R :" << l << " " << r << " = " << seg[node].LO << " " << seg[node].LC << " " << seg[node].ok << "\n";
        return;
    }
    int mid = (l+r)>>1;
    pri(l, mid, node<<1), pri(mid+1, r, node<<1|1);
    cout << "L&R :" << l << " " << r << " = " << seg[node].LO << " " << seg[node].LC << " " << seg[node].ok << "\n";
    return;
}

void test_case(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        if(c == '(') c = 0;
        else c = 1;
        str[i] = c;
    }
    build();
    //pri();
    int Q; cin >> Q;
    while(Q--){
        int idx; cin >> idx;
        if(idx == 0){
            if(seg[1].ok){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            up(idx);
        }
        //pri();
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 10, cnt = 1;
    //cin >> t;
    while(t--){
        cout << "Test " << cnt++ << ":\n";
        test_case();
    }
    return 0;
}
