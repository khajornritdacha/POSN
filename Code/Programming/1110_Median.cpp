#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn=1e6+10;
unordered_map<int,ll> mp;
int qs[mxn],N,K,a[mxn];
ll ans;
bool ok;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> a[i];
        if(a[i] > K)
            qs[i]+=1;
        else if(a[i] < K)
            qs[i]-=1;
        qs[i]+=qs[i-1];
    }

    ///qs[r]=qs[l]; l <= K.pos <= R
    ///Thus, we can add an answer if and only if it passed or current pos is K.pos
    mp[0]++;
    for(int i=1; i<=N; i++){
        //cout << qs[i] << " ";
        if(a[i] == K) ok = true;
        if(ok && mp.find(qs[i])!=mp.end()) ans+=mp[qs[i]];
        if(!ok) mp[qs[i]]++;
    }
    cout << ans << "\n";
}
