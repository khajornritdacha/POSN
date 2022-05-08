#include <bits/stdc++.h>
using namespace std;

//divide each update into 2 parts : 1.update the chunks that the entire range is the same number 2.update the last part of the last chunk so that we can maintain our order to be non-decreasing
//for instance the current elements are(additional sum from query included)
//0 1 1 1 2 2 3 3 3 3 5 5
//F 1 7 : we will increase index 2 to 6 by one and increase 9 to 10 by one so that after this operation we can increase height of plants while be able to maintain non decreasing property
//note that this is 1-indexed
//https://cses.fi/100/submit/A/

const int N = 1e5+10;

int n,Q,fen[N],a[N];

int sum(int idx){
    int res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}

void up(int idx, int val){
    if(idx <= 0) return;
    while(idx <= n){
        fen[idx] += val;
        idx += idx&-idx;
    }
}

int lb(int val){
    int l = 1, r = n, res = n+1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(sum(mid)+a[mid] >= val){
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);

    //for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i==n];

    while(Q--){
        char op; int x, y; cin >> op >> x >> y;
        if(op == 'C'){
            //cout << lb(y+1) << " " << lb(x) << "\n";
            cout << lb(y+1) - lb(x) << "\n";
        } else {
            int l1 = lb(y);
            int rt = l1+x-1;

            if(l1 > n) continue; //if fertilizer can fertilize only plants that have height greater than current maximum
            if(rt > n){ //if fertilizer can fertilize every plants until the end
                up(l1, 1);
                continue;
            }

            int rval = a[rt] + sum(rt);
            int r1 = lb(rval);


            up(l1, 1), up(r1, -1);

            int r2 = lb(rval+1), rsz = x-(r1-l1);
            up(r2-rsz, 1), up(r2, -1);
            // cout << l1 << " " << r1 << " " << r2-rsz << " " << r2 << "\n";
        }

        // cout << "SUM : ";
        // for(int i = 1; i <= n; i++){
        //     cout << sum(i) << " ";
        // }
        // cout << "\n";
    }
    return 0;
}