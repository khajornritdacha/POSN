#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;

///https://www.hackerrank.com/contests/crack-n-code-september-2021/challenges/line-art/problem

struct COOR{
    int x,y;
    bool operator<(COOR other)const{
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

struct DATA{
    int a,idx;
    bool operator<(DATA other)const{
        return a < other.a;
    }
};


int n,Q,val[N];
COOR p[N];
DATA qq[N];
pi ans[N];
set<pi> ss;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=1; i<=n; i++){
        cin >> p[i].x >> p[i].y;
    }
    sort(p+1, p+n+1);
    for(int i=1; i<=Q; i++){
        cin >> qq[i].a;
        qq[i].idx = i;
    }
    sort(qq+1, qq+n+1);

    int ps = 0, mxl = -2e9, mnl = 2e9, mxr = -2e9, mnr = 2e9;
    for(int i=1; i<=n; i++){
        val[i] = p[i].y+abs(qq[1].a-p[i].x);
        if(p[i].x < qq[1].a){
            ps = i;
            mxl = max(mxl, val[i]);
            mnl = min(mnl, val[i]);
        }else{
            ss.insert(pi(val[i], i));
            mxr = max(mxr, val[i]);
            mnr = min(mnr, val[i]);
        }
    }
    ps++;

    ans[qq[1].idx] = {min(mnl, mnr), max(mxl, mxr)};
    for(int i=2; i<=Q; i++){
        int tmp1, tmp2;
        mxl += qq[i].a-qq[i-1].a;
        mnl += qq[i].a-qq[i-1].a;
        while(ps <= n and qq[i].a > p[ps].x){
            ss.erase(pi(val[ps], ps));
            tmp1 = p[ps].y+qq[i].a-p[ps].x;
            mxl = max(mxl, tmp1);
            mnl = min(mnl, tmp1);
            ps++;
        }
        if(!ss.empty()){
            tmp1 = (*ss.rbegin()).first;
            tmp2 = (*ss.begin()).first;
            mxr = tmp1-qq[i].a+qq[1].a;
            mnr = tmp2-qq[i].a+qq[1].a;
        }else{
            mxr = -2e9, mnr = 2e9;
        }

        ans[qq[i].idx] = {min(mnl, mnr), max(mxl, mxr)};
    }

    for(int i=1; i<=Q; i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}
