#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, INF = 1e9;
using pi = pair<int,int>;
using ll = long long;

int fen[N],n,K;

struct DATA{
    int x,h,o;
    bool operator < (const DATA &o) const{
        return x < o.x;
    }
};

void up(int idx, int val){
    if(idx <= 0) return;
    while(idx < N){
        fen[idx] += val;
        idx += idx&-idx;
    }
}

int sum(int idx){
    int res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}

int ub(){
    int l = 1, r = 1e6, res = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(sum(mid) >= K){
            l = mid+1;
            res = mid;
        }else{
            r = mid-1;
        }
    }
    if(res != -1 and sum(res) != K) res = -1;
    return res;
}

int lb(){
    int l = 1, r = 1e6, res = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(sum(mid) <= K){
            r = mid-1;
            res = mid;
        }else{
            l = mid+1;
        }
    }
    if(res != -1 and sum(res) != K) res = -1;
    return res;
}

vector<DATA> ev;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        int s,h,w,o; cin >> s >> h >> w >> o;
        ev.push_back({s, h, o});
        ev.push_back({s+w, h, -o});
    }

    sort(ev.begin(), ev.end());

    // for(DATA t : ev){
    //     cout << t.x << " " << t.h << " " << t.o << "\n";
    // }

    ll ans = 0;
    for(int i = 0; i < 2*n-1; i++){
        up(1, ev[i].o);
        up(ev[i].h+1, -ev[i].o);
        int r = ub(), l = lb();
        if(r != -1){
            ans += 1ll*(r-l+1)*(ev[i+1].x-ev[i].x);
        }
    }

    cout << ans << "\n";
}