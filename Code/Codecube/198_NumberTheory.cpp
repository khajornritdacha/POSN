#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+10;
int n,m,aa[N],bb[N],ans;
ll ha[N],hb[N],pw[N],M=1e9+7,b=31;
vector<pair<int,int>> chua;
vector<ll> ones,want;
ll get_a(int l, int r){
    if(l-1 < 0) return ha[r]%M;
    return ((ha[r]-(ha[l-1]*pw[r-l+1]))%M+M)%M;
}
ll get_b(int l, int r){
    if(l-1 < 0) return hb[r]%M;
    return ((hb[r]-(hb[l-1]*pw[r-l+1]))%M+M)%M;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    pw[0] = 1;
    for(int i=1; i<=n; i++){
        cin >> aa[i];
        pw[i] = (pw[i-1]%M*b)%M;
        ha[i] = ((ha[i-1]%M*b)%M+aa[i])%M;
    }
    ones.emplace_back(0);
    for(int i=1; i<=m; i++){
        cin >> bb[i];
        if(bb[i] == 1)
            ones.emplace_back(i);
        hb[i] = ((hb[i-1]%M*b)%M+bb[i])%M;
    }
    ones.emplace_back(m+1);
    for(int i=1; i<ones.size(); i++){
        if(ones[i-1]+1 <= ones[i]-1){
            want.emplace_back(get_b(ones[i-1]+1, ones[i]-1));
            chua.emplace_back(ones[i-1]+1, ones[i]-1);
            //cout << ones[i-1]+1 << " " << ones[i]-1 << "\n";
            //cout << get_b(ones[i-1]+1, ones[i]-1) << "\n";
        }
    }
    for(int i=m; i<=n; i++){
        bool ok = true;
        //cout << "I : " << i << "\n";
        for(int j=0; j<chua.size(); j++){
            int l,r;
            tie(l,r) = chua[j];
            //cout << "POS : " << i-m+l << " " << i-m+r << "\tValue = " << get_a(i-m+l, i-m+r) << " " << want[j] << "\n";
            if(get_a(i-m+l, i-m+r) != want[j]){
                ok = false;
                break;
            }
        }
        if(ok)
            ans++;
    }
    cout << ans << '\n';
}
