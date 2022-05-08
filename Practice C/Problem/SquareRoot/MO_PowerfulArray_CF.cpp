#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;

int bs;

struct DATA{
    int l,r,idx;
    bool operator<(DATA other)const{
        if(l/bs != other.l/bs)
            return l < other.l;
        return r < other.r;
    }
};

int n,Q,a[N];
vector<DATA> queries;
ll fre[5*N],res,ans[N];

///http://codeforces.com/problemset/problem/86/D

void add(int idx){
    res -= fre[a[idx]]*fre[a[idx]]*a[idx];
    fre[a[idx]]++;
    res += fre[a[idx]]*fre[a[idx]]*a[idx];
}

void rem(int idx){
    res -= fre[a[idx]]*fre[a[idx]]*a[idx];
    fre[a[idx]]--;
    res += fre[a[idx]]*fre[a[idx]]*a[idx];
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    bs = (int)sqrt(n+.0)+1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=Q; i++){
        DATA tmp;
        cin >> tmp.l >> tmp.r;
        tmp.idx = i;
        queries.push_back(tmp);
    }

    sort(queries.begin(), queries.end());

    int nl = 0, nr = 0;
    for(DATA qq : queries){
        while(nr < qq.r){
            nr++;
            add(nr);
        }
        while(nr > qq.r){
            rem(nr);
            nr--;
        }
        while(nl < qq.l){
            rem(nl);
            nl++;
        }
        while(nl > qq.l){
            nl--;
            add(nl);
        }
        ans[qq.idx] = res;
    }
    for(int i=1; i<=Q; i++){
        cout << ans[i] << "\n";
    }
}
