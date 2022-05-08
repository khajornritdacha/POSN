#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+100;

struct DATA{
    int r,c;
    bool operator < (const DATA &other){
        if(r != other.r) return r < other.r;
        return c < other.c;
    }
};

///Let from_st[i] := the number of valid paths from (1, 1) to point i (point (R, C) is the last one)
///from_st[i] = (number of paths from (1,1) to point i) - (the number of invalid paths from previous point j * the number of ways to get from point j to point i)

int R,C,n;
ll mod = 1e9+7,from_st[3010],fa[N],ifa[N];
vector<DATA> point;

ll cal(int A, int B){
    //assert(A >= 0 and B >= 0 and A-B >= 0);
    return ((fa[A]*ifa[B])%mod*ifa[A-B])%mod;
}

ll pw(ll b, ll p){
    ll res = 1;
    while(p){
        if(p&1){
            res = (res*b)%mod;
        }
        b = (b*b)%mod;
        p /= 2;
    }
    return res;
}

int main(void){
    cin >> R >> C >> n;
    for(int i = 1; i <= n; i++){
        int r,c; cin >> r >> c;
        point.push_back({r, c});
    }
    fa[0] = ifa[0] = 1;
    for(int i = 1; i <= 2e5+10; i++){
        fa[i] = (fa[i-1]*i)%mod;
        ifa[i] = pw(fa[i], mod-2);
        //cout << fa[i] << " " << ifa[i] << "\n";
    }
    point.push_back({R, C});
    sort(point.begin(), point.end());
    for(int i = 0; i < point.size(); i++){
        from_st[i] = cal(point[i].r+point[i].c-2, point[i].r-1);
        for(int j = i-1; j >= 0; j--){
            if(point[i].r >= point[j].r and point[i].c >= point[j].c){
                from_st[i] -= (from_st[j]*cal(point[i].r-point[j].r+point[i].c-point[j].c, point[i].r-point[j].r))%mod;
                if(from_st[i] < 0) from_st[i] += mod;
            }
        }
        from_st[i] %= mod;
    }
    cout << from_st[n] << "\n";
    return 0;
}
