#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
int N,K,sz;
ll ans;
vector<ll> fen, qs;
unordered_map<ll, ll> mp(1000010);
vector<ll> vec;
void up(int i, int val){
    while(i<=sz){
        fen[i]+=val;
        i+=(i&-i);
    }
}
ll sum(int i){
    ll tmp = 0;
    while(i>=1){
        tmp+=fen[i];
        i-=i&-i;
    }
    return tmp;
}
main(){
    ///count if sum(l..r)/(r-l+1) >= K
    ///sum(a[l]...a[r]) >= K(r-l+1)
    ///minus K every index -> sum(a[l]-k,...,a[r]-k) >= 0
    ///qs[r]-qs[l-1] >= 0
    ///qs[r]>=qs[l-1]
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    qs.resize(N+1, 0);
    for(int i=1; i<=N; i++){
        cin >> qs[i];
        qs[i]-=K;
        qs[i]+=qs[i-1];
        vec.emplace_back(qs[i]);
    }
    vec.emplace_back(0);
    sort(vec.begin(), vec.end());
    int idx = 1;
    mp[vec[0]] = idx++;
    for(int i=1; i<=vec.size(); i++){
        if(vec[i]!=vec[i-1])
            mp[vec[i]] = idx++;
    }
    sz = mp.size();
    fen.resize(sz+1, 0);
    up(mp[0], 1); /// base case
    for(int i=1; i<=N; i++){
        idx = mp[qs[i]];
        ans += sum(idx);
        up(idx, 1);
    }
    cout << ans << "\n";
}
