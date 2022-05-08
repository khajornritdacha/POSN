#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using lb = long double;
using ll = long long;
using pi = pair<ll,ll>;
using tu = tuple<int,int,int>;

int P=2011,n,m,a[N],b[N],ans;
vector<int> one;
ll pw[N],ha[N],hb[N];

ll hsh(ll hh[], int l, int r){
    if(l-1 <= 0) return hh[r];
    return hh[r]-hh[l-1]*pw[r-l+1];
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    pw[0] = 1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ha[i] = ha[i-1]*P+a[i];
        pw[i] = pw[i-1]*P;
    }

    one.push_back(0);
    for(int i=1; i<=m; i++){
        cin >> b[i];
        if(b[i] == 1)
            one.push_back(i);
        hb[i] = hb[i-1]*P+b[i];
    }
    one.push_back(m+1);

    for(int i=1; i+m-1<=n; i++){
        bool ok = true;
        for(int j=1; j<one.size(); j++){
            if(one[j] == one[j-1]+1) continue;
            if(hsh(hb, one[j-1]+1, one[j]-1) != hsh(ha, one[j-1]+i, one[j]+i-2))
                ok = false;
        }
        if(ok)
            ans++;
    }
    cout << ans << "\n";
}
