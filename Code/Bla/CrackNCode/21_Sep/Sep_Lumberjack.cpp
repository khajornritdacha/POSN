#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int n,Q,bs;

struct DATA{
    int l,r,idx;
    bool operator<(DATA other)const{
        if(l/bs != other.l/bs)
            return l < other.l;
        return r < other.r;
    }
};

ll mod = 1e9+7,qs[N],a[N],ans[N];
vector<DATA> queries;

ll sum(int l, int r){
    if(l-1 <= 0) return qs[r];
    return (qs[r]-qs[l-1]+mod)%mod;
}

int main(void){
    cin >> n >> Q;
    bs = (int)sqrt(n+.0)+1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
        qs[i] %= mod;
    }
    for(int i=1; i<=Q; i++){
        DATA tmp;
        cin >> tmp.l >> tmp.r;
        tmp.idx = i;
        queries.emplace_back(tmp);
    }
    sort(queries.begin(), queries.end());

    int nl = 0, nr = 0;
    ll now = 0;
    for(DATA qq : queries){
        while(nr > qq.r){
            now -= sum(nl, nr-1)*a[nr];
            now = ((now%mod)+mod)%mod;
            nr--;
        }
        while(nr < qq.r){
            nr++;
            now += sum(nl, nr-1)*a[nr];
            now = ((now%mod)+mod)%mod;
        }
        while(nl > qq.l){
            nl--;
            now += sum(nl+1, nr)*a[nl];
            now = ((now%mod)+mod)%mod;
        }
        while(nl < qq.l){
            now -= sum(nl+1, nr)*a[nl];
            now = ((now%mod)+mod)%mod;
            nl++;
        }
        ans[qq.idx] = now;
    }
    for(int i=1; i<=Q; i++){
        cout << ans[i] << "\n";
    }
}
