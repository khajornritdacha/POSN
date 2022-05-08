#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = (1<<20)+5;

struct DATA{
    int l, r, node;
};

DATA pa[4*N];
bitset<4*N> seg;
int K, m, cnt;

void build(int l, int r, int node){
    if(l == r) return;
    int mid = (l+r)>>1, lc = node<<1, rc = lc+1;
    pa[lc] = pa[rc] = {l, r, node};
    build(l, mid, lc), build(mid+1, r, rc);
    return;
}

void add(int l, int r, int node){
    if(l == r and seg[node] == 0) cnt++;
    seg[node] = 1;
}

void up2(int l, int r, int node){
    // cout << "UP2 : " << l << " " << r << " " << node << "\n";

    if(l != r){ //update child
        int mid = (l+r)>>1, lc = node<<1, rc = lc+1;
        
        if(seg[lc] == 1 and seg[rc] == 1){ //update itself
            add(l, r, node);
        }

        if(seg[node] == 1 and seg[lc] == 0 and seg[rc] == 1){
            add(l, mid, lc);
            up2(l, mid, lc);
        } else if(seg[node] == 1 and seg[lc] == 1 and seg[rc] == 0){
            add(mid+1, r, rc);
            up2(mid+1, r, rc);
        }
    }
    
    if(node != 1){ //update parent
        up2(pa[node].l, pa[node].r, pa[node].node);
    }

    return;
}

void up1(int a, int b, int l = 1, int r = (1<<K), int node = 1){
    if(a == l and b == r){        
        // cout << "UP1 : " << l << " " << r << "\n";
        if(seg[node] == 1) return;
        add(l, r, node);
        up2(l, r, node);        
        return;
    }

    int mid = (l+r)>>1;
    if(b <= mid) up1(a, b, l, mid, node<<1);
    else up1(a, b, mid+1, r, node<<1|1);
    return;
}

void pri(int l = 1, int r = (1<<K), int node = 1){
    if(DEBUG) cout << "CHK : " << l << " " << r << " " << " = " << seg[node] << "\n";
    if(l == r) return;
    int mid = (l+r)>>1, lc = node<<1, rc = lc+1;
    pri(l, mid, lc), pri(mid+1, r, rc);
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> m;

    build(1, 1<<K, 1);

    int ans = 0;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        b++;
        up1(b, b+(1<<a)-1);
        
        if(DEBUG){
            cout << "\n-----------------------\nQUERY : " << i << "\n";
            cout << b << " " << b+(1<<a)-1 << "\n";
            pri();
            cout << "--------------------------\n";
        }

        if(cnt == (1<<K)){
            if(ans == 0){
                ans = i;
                if(DEBUG) cout << "FOUND : " << i << "\n";
            }
        }

    }

    cout << ans << "\n";

    return 0;
}