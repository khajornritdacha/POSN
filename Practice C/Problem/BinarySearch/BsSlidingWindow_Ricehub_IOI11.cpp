#include <bits/stdc++.h>
#include "ricehub.h"
using namespace std;

const int MXN = 1e5+10;
using ll = long long;

int a[MXN];

///https://oj.uz/problem/view/IOI11_ricehub
///B search to find the maximum size
///Sliding window by using current median as a center

bool chk(int sz, int R, ll B){
    int med = (sz+1)>>1;
    deque<ll> dq;
    ll rightsum = 0, leftsum = 0;
    for(int i = 1; i <= med; i++){
        leftsum += a[i];
        dq.push_back(a[i]);
    }
    for(int i = med+1; i <= R; i++){
        rightsum += a[i];
        dq.push_back(a[i]);
        if(i >= sz){
            ll tot = rightsum - 1ll*(sz-med)*(dq[med-1]) + 1ll*(med)*dq[med-1] - leftsum;
            if(tot <= B) return true;
            leftsum -= dq.front();
            leftsum += dq[med];
            rightsum -= dq[med];
            dq.pop_front();
        }
    }
    return false;
}

int besthub(int R, int L, int X[], ll B){
    for(int i = 0; i < R; i++){
        a[i+1] = X[i];
    }

    int l = 2, r = R, ans = 1;
    while(l <= r){
        int mid = (l+r)>>1;

        if(chk(mid, R, B)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans;
}
/*
int main(void){
    int R,L,B; cin >> R >> L >> B;
    int X[R] = {};
    for(int i = 0; i < R; i++){
        cin >> X[i];
    }
    cout << besthub(R, L, X, B) << "\n";
    return 0;
}
*/
